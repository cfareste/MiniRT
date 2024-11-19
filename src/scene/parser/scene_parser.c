/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:38 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 12:39:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_parser.h"
#include "utils/utils_bonus.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/camera/parser/camera_parser.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "scene/light/parser/light_parser.h"
#include "../settings/parser/scene_settings_parser.h"
#include <fcntl.h>

static int	try_parse_elems(t_parser_ctx *ctx, char **scene_args,
				t_scene *scene)
{
	int	is_char;

	is_char = ft_strlen(scene_args[0]) == 1;
	if (is_char && *scene_args[0] == AMBIENT_LIGHT_ID)
		parse_ambient_light(ctx, scene_args, &scene->ambient_light);
	else if (is_char && *scene_args[0] == CAMERA_ID[0])
		parse_camera(ctx, scene_args, &scene->camera);
	else if (is_char && (*scene_args[0] == LIGHT_ID_MANDATORY
			|| *scene_args[0] == LIGHT_ID))
		parse_light(ctx, scene_args, &scene->lights);
	else if (*scene_args[0] == *SCENE_SETTINGS_ID)
	{
		if (!try_parse_scene_setting(ctx, scene_args, &scene->settings))
			return (0);
	}
	else
		return (0);
	return (1);
}

void	parse_scene_elem(t_parser_ctx *ctx, char *line, t_scene *scene)
{
	char	**scene_args;

	scene_args = ft_split_set(line, SPACES_CHARS);
	if (!scene_args)
		throw_sys_error("ft_split");
	if (scene_args[0] && !try_parse_elems(ctx, scene_args, scene))
	{
		if (!try_parse_figure(ctx, scene_args, &scene->figures)
			&& *scene_args[0] != '#')
			throw_parse_err(ctx,
				ft_strjoin("Unknown scene parameter: ", *scene_args));
	}
	free_matrix(scene_args);
}

void	parse_scene_from_fd(t_parser_ctx *ctx, int fd, t_scene *scene)
{
	char	*line;

	ctx->line = 1;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (*line)
			parse_scene_elem(ctx, line, scene);
		free(line);
		ctx->line++;
		line = get_next_line(fd, 0);
	}
}

void	check_parsing(t_parser_ctx *ctx, t_scene *scene)
{
	t_light	*lights;
	int		mandatory_lights;

	ctx->line = 0;
	if (!scene->camera)
		throw_parse_err(ctx, "No camera provided for scene");
	lights = scene->lights;
	if (!scene->ambient_light)
			throw_parse_err(ctx, "Ambient light is missing!");
	mandatory_lights = 0;
	while (lights && mandatory_lights < 2)
	{
		if (lights->type == LIGHT_ID_MANDATORY)
			mandatory_lights++;
		lights = lights->next;
	}
	if (mandatory_lights > 1)
		throw_parse_err(ctx, "Only 1 mandatory light (L) is allowed");
}

void	parse_scene(t_scene *scene, t_textures *textures, char *filename)
{
	int				fd;
	t_parser_ctx	ctx;

	scene->filename = filename;
	pthread_mutex_init(&scene->mutex, NULL);
	ctx.textures = textures;
	ctx.filename = scene->filename;
	ctx.line = 0;
	if (!correct_file_extension(scene->filename, SCENE_FILE_EXTENSION))
		throw_parse_err(&ctx, "Only .rt files are allowed");
	fd = open(scene->filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(scene->filename);
	init_scene_settings(&scene->settings);
	scene->settings.name = get_file_name(scene->filename, SCENE_FILE_EXTENSION);
	if (!scene->settings.name)
		throw_sys_error("trying to allocate scene name");
	parse_scene_from_fd(&ctx, fd, scene);
	close(fd);
	check_parsing(&ctx, scene);
}
