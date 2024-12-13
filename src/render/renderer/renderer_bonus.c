/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/13 23:01:01 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "utils/utils_bonus.h"
#include "window/window.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/render_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "window/jobs/job/types/title/title_job.h"
#include "window/jobs/job/types/image_resize/image_resize_job.h"
#include "window/jobs/job/helpers/job_helper.h"
#include "../utils/thread/thread.h"
#include "parts/renderer_parts.h"
#include <pthread.h>

void	stop_render(t_render *render)
{
	if (!render || !render->thread)
		return ;
	set_render_finish(render, 1);
	if (render->thread)
		pthread_join(render->thread, NULL);
	render->thread = 0;
}

static void	render_cheap_mode(t_render *render, t_size *img_size, uint32_t *seed)
{
	t_strategy	strategy;
	t_size		cheap_size;

	cheap_size.width = ft_clamp(img_size->width / 2, 0, INT_MAX);
	cheap_size.height = ft_clamp(img_size->height / 2, 0, INT_MAX);
	// printf("size %dx%d\n", img_size->width, img_size->height);
	// printf("Cheap size %dx%d\n", cheap_size.width, cheap_size.height);
	wait_job(push_job(render->jobs,
			init_img_resize_job(new_job(),
				cheap_size, render->image,
				&render->image_mutex)),
		(int (*)(void *)) is_render_alive, render);
	strategy = render->strategy;
	render->strategy = NORMAL_MAP;
	render_set_resize(render, 1);
	render_parts(render, &cheap_size, seed);
	render->strategy = strategy;
	wait_job(push_job(render->jobs,
			init_img_resize_job(new_job(),
				*img_size, render->image,
				&render->image_mutex)),
		NULL, NULL);
	render_set_resize(render, 1);
}

void	*render_routine(t_window *window)
{
	t_size		img_size;
	uint32_t	seed;

	get_thread_id(&window->render.thread, &seed);
	seed *= mlx_get_time();
	if (is_render_finished(&window->render))
		return (NULL);
	img_size = get_image_size(window->render.image, &window->render.image_mutex);
	set_viewport(window->render.scene.camera,
		&window->render.scene.camera->viewport,
		&img_size);
	if (is_render_finished(&window->render))
		return (NULL);
	render_cheap_mode(&window->render, &img_size, &seed);
	if (is_render_finished(&window->render))
		return (NULL);
	render_parts(&window->render, &img_size, &seed);
	if (is_render_finished(&window->render))
		return (NULL);
	set_render_finish(&window->render, 1);
	pthread_mutex_lock(&window->render.mutex);
	printf("FINISHED RENDER: %f\n\n",
		mlx_get_time() - window->render.start_time);
	pthread_mutex_unlock(&window->render.mutex);
	return (NULL);
}

// static void	prepare_render(t_window *window)
// {
// 	stop_render(&window->render);
// 	pthread_mutex_lock(&window->render.image_mutex);
// 	mlx_resize_image(window->render.image,
// 		window->mlx->width, window->mlx->height);
// 	pthread_mutex_unlock(&window->render.image_mutex);
// }

void	render(t_window *window_)
{
	t_window	*window;
	// int			scene_ready;

	window = (t_window *) window_;
	stop_render(&window->render);
	// prepare_render(window);
	// pthread_mutex_lock(&window->render.scene.mutex);
	// scene_ready = window->render.scene.ready;
	// pthread_mutex_unlock(&window->render.scene.mutex);
	// if (!scene_ready)
	// 	return ;
	printf("RENDERING\n");
	pthread_mutex_lock(&window->render.mutex);
	window->render.start_time = mlx_get_time();
	pthread_mutex_unlock(&window->render.mutex);
	set_render_finish(&window->render, 0);
	if (is_render_alive(&window->render)
		&& pthread_create(&window->render.thread, NULL,
			(void *(*)(void*)) render_routine, window))
		throw_sys_error("creating new render thread");
}
