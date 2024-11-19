/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/19 15:45:01 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "window/window.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/renderer/renderer_bonus.h"
#include "scene/parser/scene_parser.h"
#include "loader/multi_loader_bonus.h"
#include "utils/utils_bonus.h"

void	destroy(t_window *window)
{
	pthread_join(window->exporter.thread, NULL);
	destroy_loader(&window->render.loader);
	mlx_delete_texture(window->icon);
	mlx_terminate(window->mlx);
	destroy_jobs(&window->jobs);
	destroy_scene_settings(&window->render.scene.settings);
	free_textures(&window->textures);
	free(window->render.scene.ambient_light);
	free(window->render.scene.camera);
	free_lights(window->render.scene.lights);
	free_figures(window->render.scene.figures);
}

static void	*start_routine(void *window_)
{
	t_window	*window;

	window = (t_window *) window_;
	loader_show_animation(&window->loader, 1, window->size);
	load_textures(&window->loader, &window->textures, &window->jobs);
	loader_hide(&window->loader);
	pthread_mutex_lock(&window->render.scene.mutex);
	window->render.scene.ready = 1;
	pthread_mutex_unlock(&window->render.scene.mutex);
	render(window);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_window		window;
	pthread_t		thread;

	if (argc != 2)
		return (ft_printff(STDERR_FILENO, "Wrong arguments! " \
			"usage: ./miniRT assets/scenes/scene.rt\n"), EXIT_FAILURE);
	ft_bzero(&window, sizeof(t_window));
	parse_scene(&window.render.scene, &window.textures, argv[1]);
	init_window(&window);
	pthread_create(&thread, NULL, start_routine, &window);
	mlx_loop(window.mlx);
	pthread_join(thread, NULL);
	return (destroy(&window), EXIT_SUCCESS);
}
