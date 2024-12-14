/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/14 15:24:18 by arcanava         ###   ########.fr       */
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

static void	render_cheap(t_render *render, t_size *img_size, uint32_t *seed)
{
	t_strategy	strategy;
	t_strategy	cheap_strategy;

	cheap_strategy = get_async_flag(&render->cheap_strategy);
	if (cheap_strategy == render->strategy
		|| get_async_flag(&render->dis_cheap_once))
		return (set_async_flag(&render->dis_cheap_once, 0));
	strategy = render->strategy;
	render->strategy = cheap_strategy;
	render_parts(render, img_size, seed);
	render->strategy = strategy;
}

void	*render_routine(t_window *window)
{
	t_size		img_size;
	uint32_t	seed;

	get_thread_id(&window->render.thread, &seed);
	seed *= mlx_get_time();
	if (is_render_finished(&window->render))
		return (NULL);
	img_size = get_image_size(window->render.image,
			&window->render.image_mutex);
	set_viewport(window->render.scene.camera,
		&window->render.scene.camera->viewport,
		&img_size);
	if (is_render_alive(&window->render)
		&& get_async_flag(&window->render.cheap))
		render_cheap(&window->render, &img_size, &seed);
	if (is_render_alive(&window->render)
		&& !get_render_update(&window->render))
		render_parts(&window->render, &img_size, &seed);
	return (NULL);
}

static void	prepare_render(t_window *window)
{
	stop_render(&window->render);
	pthread_mutex_lock(&window->render.image_mutex);
	mlx_resize_image(window->render.image,
		window->mlx->width, window->mlx->height);
	pthread_mutex_unlock(&window->render.image_mutex);
}

void	render(t_window *window_)
{
	t_window	*window;

	window = (t_window *) window_;
	stop_render(&window->render);
	set_render_finish(&window->render, 0);
	prepare_render(window);
	printf("RENDERING\n");
	pthread_mutex_lock(&window->render.mutex);
	window->render.start_time = mlx_get_time();
	pthread_mutex_unlock(&window->render.mutex);
	if (is_render_alive(&window->render)
		&& pthread_create(&window->render.thread, NULL,
			(void *(*)(void*)) render_routine, window))
		throw_sys_error("creating new render thread");
}
