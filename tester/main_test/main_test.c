/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:47:43 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:55:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "miniRT.h"
#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "window/jobs/jobs.h"
#include "render/renderer/renderer.h"
#include "scene/parser/scene_parser.h"
#include "scene/settings/sky_box/sky_box.h"
#include "window/loader/loader.h"
#include "exporter/helpers/exporter_helper.h"
#include "utils/utils.h"

void	throw_sys_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	destroy(t_window *window)
{
	free(window->render.scene.ambient_light);
	free(window->render.scene.camera);
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
	parse(&window, argv[1]);
	return (EXIT_SUCCESS);
}
