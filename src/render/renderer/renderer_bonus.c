/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/15 17:58:18 by arcanava         ###   ########.fr       */
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

static void	render_cheap(t_render *render, uint32_t *seed)
{
	t_strategy	cheap_strategy;

	cheap_strategy = get_async_flag(&render->cheap_strategy);
	if (!is_render_alive(render)
		|| !get_async_flag(&render->cheap)
		|| cheap_strategy == render->strategy
		|| get_async_flag(&render->dis_cheap_once))
		return (set_async_flag(&render->dis_cheap_once, 0));
	shuffle_pixels(render->pixels, render->px_amount, seed);
	render_parts(render, cheap_strategy);
}

static void	prepare(int *persist, t_render *render,
				uint32_t *seed, t_size *img_size)
{
	*img_size = get_image_size(render->image, &render->image_mutex);
	*persist = get_async_flag(&render->persist_prog);
	set_async_flag(&render->persist_prog, 0);
	get_thread_id(&render->thread, seed);
	*seed *= mlx_get_time();
	if (get_async_flag(&render->resize))
	{
		fill_pixels(*img_size, &render->pixels, &render->px_amount);
		update_parts(render, img_size);
	}
}

void	*render_routine(t_window *window)
{
	t_size		img_size;
	uint32_t	seed;
	int			persist;

	prepare(&persist, &window->render, &seed, &img_size);
	if (is_render_finished(&window->render))
		return (NULL);
	set_viewport(window->render.scene.camera,
		&window->render.scene.camera->viewport,
		&img_size);
	render_cheap(&window->render, &seed);
	if (is_render_alive(&window->render)
		&& !get_async_flag(&window->render.update))
		render_prog_parts(&window->render, &seed, persist,
			window->render.strategy);
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
