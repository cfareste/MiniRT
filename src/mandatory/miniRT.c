/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:01:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "miniRT.h"
#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "render/renderer/renderer.h"

void	main_destroy(t_window *window)
{
	mlx_delete_texture(window->icon);
	mlx_terminate(window->mlx);
	free(window->render.scene.ambient_light);
	free(window->render.scene.camera);
	free(window->filename);
	free_lights(window->render.scene.lights);
	free_figures(window->render.scene.figures);
}

int	main(int argc, char **argv)
{
	t_window		window;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments! " \
			"usage: ./miniRT assets/scenes/scene.rt\n"), EXIT_FAILURE);
	ft_bzero(&window, sizeof(t_window));
	get_window(&window);
	parse(&window, argv[1]);
	init_window(&window);
	render(&window.render);
	mlx_loop(window.mlx);
	return (main_destroy(&window), EXIT_SUCCESS);
}
