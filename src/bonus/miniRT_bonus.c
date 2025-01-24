/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "miniRT_bonus.h"
#include "window/window_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "window/jobs/jobs_bonus.h"
#include "render/progressive/helpers/progressive_helper_bonus.h"
#include "scene/settings/sky_box/sky_box_bonus.h"

void	main_destroy(t_window *window)
{
	mlx_delete_texture(window->icon);
	mlx_terminate(window->mlx);
	destroy_jobs(&window->jobs);
	clean_progress(window->render.progress);
	destroy_scene_settings(&window->render.scene.settings);
	free_textures(&window->textures);
	free(window->render.scene.ambient_light);
	free(window->render.scene.camera);
	free(window->render.pixels);
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
	load_textures(&window.textures);
	configure_sky_box(&window.render.scene);
	init_window(&window);
	mlx_loop(window.mlx);
	return (main_destroy(&window), EXIT_SUCCESS);
}
