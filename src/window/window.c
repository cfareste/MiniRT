/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/15 18:41:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "window.h"
#include "utils/utils_bonus.h"
#include "helpers/window_helper_bonus.h"
#include "scene/settings/scene_settings.h"
#include "render/renderer/renderer_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "exporter/exporter_bonus.h"
#include "scene/camera/helpers/camera_helper.h"
#include "scene/camera/events/camera_events.h"
#include "jobs/job/job.h"
#include "miniRT.h"
#include "window/loader/helpers/loader_helper.h"
#include "render/events/render_events.h"
#include "events/window_events.h"
#include "scene/settings/sky_box/sky_box.h"
#include "render/renderer/parts/renderer_parts.h"
#include "render/progressive/helpers/progressive_helper.h"

static void	control(t_window *window)
{
	int	update;

	update = 0;
	if (window->render.scene.selection)
		update = control_figure(window->render.scene.selection,
				window->render.scene.camera, &window->controls);
	else
	{
		update = control_camera(window->render.scene.camera, &window->controls);
		if (update)
		{
			set_viewport(window->render.scene.camera,
				&window->render.scene.camera->viewport,
				get_image_size(window->render.image,
					&window->render.image_mutex));
			configure_sky_box(&window->render.scene);
		}
	}
	if (update)
	{
		window->last_update = mlx_get_time();
		set_async_flag(&window->render.update, 1);
	}
}

static void	main_loop(void *window_)
{
	t_window	*window;

	window = (t_window *) window_;
	exec_jobs(&window->jobs, window);
	if (window->resize.to_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		window->resize.to_resize = 0;
		set_size(&window->size,
			window->resize.size.width, window->resize.size.height);
		loader_set_resize(window->exporter.loader, 1);
		set_async_flag(&window->render.resize, 1);
		set_async_flag(&window->render.update, 1);
	}
	else if (window->controls.moving
		&& !get_async_flag(&window->render.blocked)
		&& mlx_get_time() - window->last_update > KEY_REPEAT_RATE)
		control(window);
	if (get_async_flag(&window->render.update))
	{
		set_async_flag(&window->render.update, 0);
		render(window);
	}
}

void	close_window(t_window *window)
{
	destroy_composer(&window->composer);
	destroy_exporter(&window->exporter);
	destroy_render(&window->render);
	mlx_close_window(window->mlx);
}

static void	set_hooks(t_window *window)
{
	mlx_key_hook(window->mlx, (mlx_keyfunc) key_hook, window);
	mlx_scroll_hook(window->mlx, scroll_hook, window);
	mlx_resize_hook(window->mlx, (mlx_resizefunc) resize_hook, window);
	mlx_cursor_hook(window->mlx,
		(mlx_cursorfunc) cursor_update_pos, &window->cursor);
	mlx_mouse_hook(window->mlx, (mlx_mousefunc) mouse_hook, window);
	mlx_close_hook(window->mlx, (mlx_closefunc) close_window, window);
	mlx_loop_hook(window->mlx, main_loop, window);
}

void	init_window(t_window *window)
{
	char	*title;

	pthread_mutex_init(&window->jobs.mutex, NULL);
	pthread_mutex_init(&window->size.mutex, NULL);
	pthread_mutex_init(&window->render.scene.selection_mutex, NULL);
	window->icon = mlx_load_png(ICON_PATH);
	title = safe_ft_strjoin(window->render.scene.settings.name,
			PROGRAM_NAME_SUFF, throw_sys_error, "allocating title");
	window->mlx = mlx_init(window->size.width, window->size.height,
			title, true);
	free(title);
	window->last_scroll = mlx_get_time();
	window->last_update = mlx_get_time();
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	init_cursor(&window->cursor);
	init_loader(&window->loader, &window->jobs, window->mlx, &window->size);
	init_composer(&window->composer, &window->render,
		&window->jobs, &window->filename);
	init_exporter(&window->exporter, &window->render,
		&window->jobs, &window->loader);
	init_render(&window->render, window->mlx);
	set_hooks(window);
}
