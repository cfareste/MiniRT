/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 13:38:27 by arcanava         ###   ########.fr       */
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
#include "jobs/job/job.h"
#include "miniRT.h"

static void	main_loop(void *window_)
{
	t_window	*window;

	window = (t_window *) window_;
	exec_jobs(&window->jobs, window);
	if (window->resize.last_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		stop_render(&window->render);
		window->resize.last_resize = 0;
		window->size = window->resize.size;
		render(window);
	}
}

static void	close_window(t_window *window)
{
	stop_render(&window->render);
	mlx_close_window(window->mlx);
}

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.action != MLX_PRESS)
		return ;
	else if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		close_window(window);
	else if (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F5)
		render(window);
	else if (keydata.key == MLX_KEY_I)
	{
		update_camera_fov(window->render.scene.camera, -1);
		render(window);
	}
	else if (keydata.key == MLX_KEY_O)
	{
		update_camera_fov(window->render.scene.camera, 1);
		render(window);
	}
	else if (keydata.key == MLX_KEY_E)
		export_image(&window->exporter, &window->jobs);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_window		*window;

	(void) xdelta;
	window = (t_window *) param;
	if (mlx_get_time() - window->last_scroll < 0.2)
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
	pthread_mutex_lock(&window->ready);
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	window->icon = mlx_load_png(ICON_PATH);
	window->mlx = mlx_init(window->size.width, window->size.height,
			PROGRAM_NAME, true);
	window->last_scroll = mlx_get_time();
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	init_multi_loader(&window->loader, window->mlx);
	init_exporter(&window->exporter, &window->render, &window->jobs);
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
