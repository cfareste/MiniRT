/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 23:04:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "helpers/window_helper_bonus.h"
#include "render/renderer/renderer_bonus.h"
#include "miniRT_bonus.h"

static void	global_hook(t_window *window)
{
	if (window->resize.last_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		stop_render(&window->render);
		window->resize.last_resize = 0;
		window->size = window->resize.size;
		render(&window->render, window->mlx);
	}
}

static void	close_window(t_window *window)
{
	stop_render(&window->render);
	mlx_close_window(window->mlx);
}

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		close_window(window);
	else if (keydata.action == MLX_PRESS
		&& (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F5))
		render(&window->render, window->mlx);
}

void	init_window(t_window *window)
{
	int	width;
	int	height;

	mlx_get_monitor_size(0, &width, &height);
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	if (width > 0)
		window->size.width = width;
	if (height > 0)
		window->size.height = height;
	// #ifndef COMPACT_VERSION
	// window->icon = mlx_load_png(ICON_PATH);
	// #endif
	window->mlx = mlx_init(window->size.width, window->size.height,
			window->render.scene.name, true);
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	mlx_key_hook(window->mlx,
		(void (*)(mlx_key_data_t keydata, void *)) key_hook, window);
	mlx_resize_hook(window->mlx,
		(void (*)(int, int, void *)) window_resized, window);
	mlx_loop_hook(window->mlx, (void (*)(void *)) global_hook, window);
	mlx_close_hook(window->mlx, (void (*)(void *)) close_window, window);
}
