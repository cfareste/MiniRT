/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:46:42 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "window.h"
#include "utils/utils.h"
#include "helpers/window_helper.h"
#include "render/renderer/renderer.h"
#include "miniRT.h"

static void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		return (close_window(window));
}

static void	main_loop(void *window_)
{
	(void) window_;
}

void	close_window(t_window *window)
{
	mlx_close_window(window->mlx);
}

static void	set_hooks(t_window *window)
{
	mlx_key_hook(window->mlx, (mlx_keyfunc) key_hook, window);
	mlx_close_hook(window->mlx, (mlx_closefunc) close_window, window);
	mlx_loop_hook(window->mlx, main_loop, window);
}

void	init_window(t_window *window)
{
	window->icon = mlx_load_png(ICON_PATH);
	window->size.width = 1600;
	window->size.height = 900;
	window->mlx = mlx_init(window->size.width, window->size.height,
			PROGRAM_NAME, false);
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	init_render(&window->render, window->mlx);
	set_hooks(window);
}
