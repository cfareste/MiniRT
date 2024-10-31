/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/31 11:56:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "window/window.h"
#include "render/renderer/renderer_bonus.h"
#include "render/scene/parser/scene_parser.h"
#include "parser/parser.h"

void	destroy(t_window *window)
{
	destroy_loader(&window->render.loader);
	mlx_terminate(window->mlx);
	mlx_delete_texture(window->icon);
	free(window->render.scene.name);
	free(window->render.scene.ambient_light);
	free(window->render.scene.camera);
	free_lights(window->render.scene.lights);
	free_figures(window->render.scene.figures);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments!\n"), EXIT_FAILURE);
	ft_bzero(&window, sizeof(t_window));
	parse_scene_from_file(&window.render.scene, argv[1]);
	init_window(&window);
	mlx_loop(window.mlx);
	return (destroy(&window), EXIT_SUCCESS);
}
