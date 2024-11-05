/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 20:46:50 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "window/window.h"
#include "render/renderer/renderer_bonus.h"
#include "render/scene/parser/scene_parser.h"
#include "parser/parser.h"
#include <emscripten/html5.h>
#include <emscripten/emscripten.h>

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

void emscripten_main_loop(mlx_t *mlx)
{
    mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_window	window;

	ft_bzero(&window, sizeof(t_window));
	parse_scene_from_file(&window.render.scene, "./multicolored_spheres.rt");
	init_window(&window);
	init_render(&window.render, window.mlx);
	render(&window.render, window.mlx);
	emscripten_set_main_loop_arg((void (*)(void *)) emscripten_main_loop,
		window.mlx, 30, true);
	mlx_loop(window.mlx);
	return (destroy(&window), EXIT_SUCCESS);
}
