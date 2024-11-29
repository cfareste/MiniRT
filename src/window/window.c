/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/29 14:46:22 by arcanava         ###   ########.fr       */
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

static void	main_loop(void *window_)
{
	t_window	*window;

	printf("looping...\n");
	window = (t_window *) window_;
	exec_jobs(&window->jobs, window);
	if (window->resize.last_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		window->resize.last_resize = 0;
		window->size = window->resize.size;
		render(window);
	}
}

static void	close_window(t_window *window)
{
	t_job	*job;

	printf("JOBS:\n");
	job = window->jobs.job;
	while(job)
	{
		printf("Job: %p\n", job);
		job = job->next;
	}
	printf("\n");
	destroy_exporter(&window->exporter);
	stop_render(&window->render);
	printf("Cierro la ventana cabron \n");
	mlx_close_window(window->mlx);
}

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			close_window(window);
		if (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F5)
			render(window);
		if (keydata.key == MLX_KEY_E)
			export_image(&window->exporter, &window->jobs);
		if (keydata.key == MLX_KEY_L)
			loader_hide(window->exporter.loader);
		if (keydata.key == MLX_KEY_1 || keydata.key == MLX_KEY_2)
		{
			if (keydata.key == MLX_KEY_1)
				window->render.raytracing = 1;
			else
				window->render.raytracing = 0;
			render(window);
		}
	}
	camera_key_events(keydata, window);
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
	pthread_mutex_init(&window->jobs.mutex, NULL);
	pthread_mutex_lock(&window->ready);
	window->icon = mlx_load_png(ICON_PATH);
	window->mlx = mlx_init(window->size.width, window->size.height,
			PROGRAM_NAME, true);
	window->last_scroll = mlx_get_time();
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	init_loader(&window->loader, &window->jobs, window->mlx);
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
