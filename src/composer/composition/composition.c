/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 19:57:19 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "composition.h"
#include "utils/utils_bonus.h"
#include "./helpers/lights/composition_lights_helpers.h"
#include "./helpers/figures/composition_figures_helpers.h"
#include "./helpers/settings/composition_settings_helpers.h"
#include "libft.h"
#include <fcntl.h>

static int	open_rt_file(char **filename_ref, int create_new_file)
{
	int		fd;
	char	*new_filename;
	char	*parenthesis_pos;
	char	*new_path;

	if (create_new_file == MODIFY_EXISTING)
	{
		fd = open(*filename_ref, O_TRUNC | O_WRONLY);
		return (fd);
	}
	parenthesis_pos = ft_strrchr(*filename_ref, '(');
	if (parenthesis_pos)
		(*filename_ref)[parenthesis_pos - *filename_ref] = '\0';
	new_filename = get_file_name(*filename_ref, FILE_EXTENSION);
	new_path = set_file_name(new_filename, FILE_EXTENSION, "assets/scenes/", 0);
	free(*filename_ref);
	free(new_filename);
	*filename_ref = new_path;
	fd = open(*filename_ref, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (fd);
}

static int	fill_buffer(t_composer *composer, char **buffer)
{
	*buffer = NULL;
	if (fill_render(composer, composer->render, buffer)
		|| fill_scene(composer, &composer->render->scene, buffer)
		|| fill_window(composer, composer->render, buffer)
		|| fill_ambient(composer, composer->render->scene.ambient_light, buffer)
		|| fill_lights(composer, composer->render->scene.lights, buffer)
		|| fill_camera(composer, composer->render->scene.camera, buffer)
		|| fill_figures(composer, composer->render->scene.figures, buffer))
		return (-1);
	return (ft_strlen(*buffer));
}

void	*composition_routine(t_composition *composition)
{
	char	*compose_buffer;
	int		buffer_length;
	int		fd;

	if (!composer_is_alive(composition->composer))
		return (free(composition), NULL);
	set_async_flag(&composition->composer->render->blocked, 1);
	buffer_length = fill_buffer(composition->composer, &compose_buffer);
	if (composer_is_alive(composition->composer) && buffer_length > 0)
	{
		fd = open_rt_file(composition->composer->filename_ref,
				composition->create_new_file);
		if (fd == -1)
			throw_sys_error("opening composing file");
		write(fd, compose_buffer, buffer_length);
		close(fd);
		composition->composer->render->scene.orig_camera
			= *composition->composer->render->scene.camera;
	}
	composer_set_alive(composition->composer, 0);
	set_async_flag(&composition->composer->render->blocked, 0);
	free(compose_buffer);
	return (free(composition), NULL);
}
