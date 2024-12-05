/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/05 22:49:04 by arcanava         ###   ########.fr       */
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
#include "../utils/thread/thread.h"
#include "parts/renderer_parts.h"
#include <pthread.h>

void	stop_render(t_render *render)
{
	if (!render || !render->thread)
		return ;
	set_render_finish(render, 1);
	pthread_join(render->thread, NULL);
}

void	*render_routine(t_window *window)
{
	t_size		img_size;
	uint32_t	seed;

	get_thread_id(&window->render.thread, &seed);
	seed *= mlx_get_time();
	set_render_finish(&window->render, 0);
	if (is_render_finished(&window->render) || !window->render.image)
		return (NULL);
	img_size = get_image_size(window->render.image,
			&window->render.image_mutex);
	set_viewport(window->render.scene.camera,
		&window->render.scene.camera->viewport, img_size);
	render_parts(&window->render, img_size, &seed);
	if (is_render_finished(&window->render))
		return (NULL);
	set_render_finish(&window->render, 1);
	pthread_mutex_lock(&window->render.mutex);
	printf("FINISHED RENDER: %f\n\n",
		mlx_get_time() - window->render.start_time);
	pthread_mutex_unlock(&window->render.mutex);
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
	int			scene_ready;

	window = (t_window *) window_;
	prepare_render(window);
	pthread_mutex_lock(&window->render.scene.mutex);
	scene_ready = window->render.scene.ready;
	pthread_mutex_unlock(&window->render.scene.mutex);
	if (!scene_ready)
		return ;
	printf("RENDERING\n");
	pthread_mutex_lock(&window->render.mutex);
	window->render.start_time = mlx_get_time();
	pthread_mutex_unlock(&window->render.mutex);
	if (pthread_create(&window->render.thread, NULL,
			(void *(*)(void*)) render_routine, window))
		throw_sys_error("creating new render thread");
}
