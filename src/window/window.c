/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/04 22:12:27 by arcanava         ###   ########.fr       */
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

static void	main_loop(void *window_)
{
	t_window	*window;
	int			to_render;

	window = (t_window *) window_;
	to_render = 0;
	exec_jobs(&window->jobs, window);
	if (window->resize.last_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		window->resize.last_resize = 0;
		set_size(&window->size,
			window->resize.size.width, window->resize.size.height);
		loader_set_resize(window->exporter.loader, 1);
		to_render = 1;
	}
	else if (!window->render.blocked
		&& mlx_get_time() - window->last_update > KEY_REPEAT_RATE
		&& window->render.scene.camera->controls.moving)
	{
		update_camera(window->render.scene.camera);
		window->last_update = mlx_get_time();
		to_render = 1;
	}
	if (to_render)
		render(window);
}

static void	close_window(t_window *window)
{
	destroy_exporter(&window->exporter);
	stop_render(&window->render);
	mlx_close_window(window->mlx);
}

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			close_window(window);
		if (keydata.key == MLX_KEY_E)
			export_image(&window->exporter, &window->jobs);
		if (keydata.key == MLX_KEY_L)
			loader_toggle_visibility(window->exporter.loader);
	}
	render_key_events(&keydata, window);
	camera_key_events(keydata, window);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_window		*window;

	(void) xdelta;
	window = (t_window *) param;
	if (window->render.blocked || mlx_get_time() - window->last_scroll < 0.2)
		return ;
	stop_render(&window->render);
	if (ydelta <= -1.0)
		update_camera_fov(window->render.scene.camera, 1);
	else if (ydelta >= 1.0)
		update_camera_fov(window->render.scene.camera, -1);
	else
		return ;
	window->last_scroll = mlx_get_time();
	render(window);
}

void	init_window(t_window *window)
{
	pthread_mutex_init(&window->ready, NULL);
	pthread_mutex_init(&window->jobs.mutex, NULL);
	pthread_mutex_init(&window->size.mutex, NULL);
	pthread_mutex_lock(&window->ready);
	window->icon = mlx_load_png(ICON_PATH);
	window->mlx = mlx_init(window->size.width, window->size.height,
			PROGRAM_NAME, true);
	window->last_scroll = mlx_get_time();
	window->last_update = mlx_get_time();
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	init_loader(&window->loader, &window->jobs, window->mlx, &window->size);
	init_exporter(&window->exporter, &window->render,
		&window->jobs, &window->loader);
	init_render(&window->render, window->mlx);
	mlx_key_hook(window->mlx,
		(void (*)(mlx_key_data_t keydata, void *)) key_hook, window);
	mlx_resize_hook(window->mlx,
		(void (*)(int, int, void *)) window_resized, window);
	mlx_loop_hook(window->mlx, main_loop, window);
	mlx_close_hook(window->mlx, (void (*)(void *)) close_window, window);
	mlx_scroll_hook(window->mlx, scroll_hook, window);
	pthread_mutex_unlock(&window->ready);
}
