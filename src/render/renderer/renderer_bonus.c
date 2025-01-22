/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/22 14:24:49 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer_bonus.h"
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

static void	set_args(t_render_args *args, t_render *render)
{
	args->persist = get_async_flag(&render->persist_prog);
	if (args->persist)
		set_async_flag(&render->persist_prog, 0);
	args->resize = get_async_flag(&render->resize);
	if (args->resize)
		set_async_flag(&render->resize, 0);
	args->prog_enabled = get_async_flag(&render->prog_enabled);
	args->strategy = get_async_flag(&render->strategy);
	args->cheap_enabled = get_async_flag(&render->cheap);
	args->dis_cheap_once = get_async_flag(&render->dis_cheap_once);
	if (args->dis_cheap_once)
		set_async_flag(&render->dis_cheap_once, 0);
	args->cheap_strategy = get_async_flag(&render->cheap_strategy);
}

static void	prepare(t_render_args *args, t_render *render,
				uint64_t *seed)
{
	t_window	*window;

	window = get_window(NULL);
	get_thread_id(&render->thread, seed);
	*seed *= mlx_get_time();
	set_args(args, render);
	if (args->resize)
	{
		wait_job(push_job(&window->jobs, init_img_resize_job(new_job(),
					window->size, render->image, NULL)),
			(int (*)(void *)) is_render_alive, render);
		fill_pixels(window->size, &render->pixels, &render->px_amount);
		update_parts(render, &window->size);
		set_viewport(render->scene.camera,
			&render->scene.camera->viewport, window->size);
	}
}

static void	*render_routine(t_render *render)
{
	uint64_t		seed;
	t_render_args	args;

	prepare(&args, render, &seed);
	if (is_render_alive(render) && args.cheap_enabled && !args.dis_cheap_once)
		render_parts(render, args.cheap_strategy, &seed);
	if (is_render_alive(render) && args.prog_enabled)
		render_prog_parts(&args, render, &seed);
	set_render_finish(render, 1);
	printf("Finished render in %.3f seconds\n\n",
		mlx_get_time() - render->start_time);
	return (NULL);
}

void	render(t_render *render)
{
	stop_render(render);
	set_render_finish(render, 0);
	printf("RENDERING\n");
	render->start_time = mlx_get_time();
	if (is_render_alive(render)
		&& pthread_create(&render->thread, NULL,
			(void *(*)(void*)) render_routine, render))
		throw_sys_error("creating new render thread");
}
