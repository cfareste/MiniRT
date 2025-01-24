/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:47:43 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 13:54:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "miniRT_bonus.h"
#include "window/window_bonus.h"
#include "window/helpers/window_helper_bonus_bonus.h"
#include "window/jobs/jobs_bonus.h"
#include "window/jobs/job/types/title/title_job_bonus.h"
#include "render/renderer/renderer_bonus_bonus.h"
#include "scene/parser/scene_parser_bonus.h"
#include "scene/settings/sky_box/sky_box_bonus.h"
#include "window/loader/loader_bonus_bonus.h"
#include "exporter/helpers/exporter_helper_bonus_bonus.h"
#include "utils/utils_bonus_bonus.h"

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
