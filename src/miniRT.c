/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 22:49:37 by arcanava         ###   ########.fr       */
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
	char		*thing;
	
	
	thing = "A  0.5 50,50,50\n \
		#C -4,2,-1 3,-.5,-.3 90 \n \
#C 0,0,4 0,0,-1 90 \n\
# C 0,0,4 0,0,-1 90 \n\n\
C 0,160,80 0,-1,-0.5 175 \n\
L -6,0,-1 1.0 200,0,0 \n\
l 0,0,-1 1 0,200,0 \n\
l 6,0,-1 1.0 0,0,200 \n\
sp 4,2,-3   12 23 1    .5      255,255,255 \n\
sp 0,2,-3   12 23 1   2.0      255,255,255 \n\
sp -4,2,-3  12 23 1    2.0      255,255,255 \n\
sp 4,0,-3   12 23 1     2.0      255,255,255 \n\
sp 0,0,-3   12 23 1     2.0      255,255,255 \n\
sp -4,0,-3  12 23 1      2.0     255,255,255 \n\
sp 4,-2,-3  12 23 1   2.0      255,255,255 \n\
sp 0,-2,-3  12 23 1   2.0      255,255,255 \n\
sp -4,-2,-3 12 23 1    2.0      255,255,255 \n\
co 0,0,0 2 2 2 0,0,0 3.0 4.0 255,255,255 \n\
sp 0,0,-45 3 2 2   80.0    255,255,255";
	ft_bzero(&window, sizeof(t_window));
	parse_scene_from_str(&window.render.scene, thing);
	init_window(&window);
	render(&window.render, window.mlx);
	mlx_loop(window.mlx);
	return (destroy(&window), EXIT_SUCCESS);
}
