/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:11 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/17 20:11:19 by cfidalgo         ###   ########.fr       */
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

static int	is_file_id(char *str)
{
	int	i;

	if (!str || str[0] == '.')
		return (0);
	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	open_rt_file(char **filename_ref, int create_new_file)
{
	int		fd;
	char	*new_filename;
	char	*underline_pos;
	char	*new_path;
	char	*extension;

	if (create_new_file == MODIFY_EXISTING)
	{
		fd = open(*filename_ref, O_TRUNC | O_WRONLY);
		return (fd);
	}
	extension = FILE_EXTENSION;
	underline_pos = ft_strrchr(*filename_ref, '_');
	if (underline_pos && is_file_id(underline_pos + 1))
	{
		(*filename_ref)[underline_pos - *filename_ref] = '\0';
		extension = "";
	}
	new_filename = get_file_name(*filename_ref, extension);
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

static void	write_file(int fd, t_composer *composer, char *buff, int buff_len)
{
	write(fd, buff, buff_len);
	close(fd);
	composer->render->scene.orig_camera = *composer->render->scene.camera;
	printf("Saved file as %s\n", *composer->filename_ref);
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
		if (fd != -1)
			write_file(fd, composition->composer, compose_buffer,
				buffer_length);
		else
			ft_printff(STDERR_FILENO, "Error\nFailed to save file\n");
	}
	composer_set_alive(composition->composer, 0);
	set_async_flag(&composition->composer->render->blocked, 0);
	free(compose_buffer);
	free(composition);
	return (NULL);
}
