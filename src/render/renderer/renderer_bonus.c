/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/19 21:19:03 by arcanava         ###   ########.fr       */
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

void	render_cheap(t_render *render, t_size *img_size, uint32_t *seed)
{
	t_strategy	strategy;
	t_strategy	cheap_strategy;
	int			prog_enabled;

	cheap_strategy = get_async_flag(&render->cheap_strategy);
	if (cheap_strategy == render->strategy
		|| get_async_flag(&render->dis_cheap_once))
		return (set_async_flag(&render->dis_cheap_once, 0));
	strategy = render->strategy;
	prog_enabled = get_async_flag(&render->prog_enabled);
	render->strategy = cheap_strategy;
	set_async_flag(&render->prog_enabled, 0);
	render_parts(render, img_size, seed, 0);
	set_async_flag(&render->prog_enabled, prog_enabled);
	render->strategy = strategy;
}

void	*render_routine(t_window *window)
{
	t_size		img_size;
	uint32_t	seed;
	int			persist;

	persist = get_async_flag(&window->render.persist_prog);
	set_async_flag(&window->render.persist_prog, 0);
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
		&& !get_async_flag(&window->render.update))
		render_parts(&window->render, &img_size, &seed, persist);
	set_render_finish(&window->render, 1);
	printf("Finished render in %.3f seconds\n\n",
		mlx_get_time() - window->render.start_time);
	return (NULL);
}

void	render(t_window *window_)
{
	t_window	*window;

	window = (t_window *) window_;
	stop_render(&window->render);
	set_render_finish(&window->render, 0);
	printf("RENDERING\n");
	window->render.start_time = mlx_get_time();
	mlx_resize_image(window->render.image,
		window->mlx->width, window->mlx->height);
	if (is_render_alive(&window->render)
		&& pthread_create(&window->render.thread, NULL,
			(void *(*)(void*)) render_routine, window))
		throw_sys_error("creating new render thread");
}
