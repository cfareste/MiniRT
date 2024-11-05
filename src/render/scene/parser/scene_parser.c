/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:40:38 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 20:45:43 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_parser.h"
#include "utils/utils_bonus.h"
#include "render/scene/figure/parser/figure_parser.h"
#include "render/scene/camera/parser/camera_parser.h"
#include "render/scene/light/ambient_light/ambient_light.h"
#include "render/scene/light/parser/light_parser.h"
#include <fcntl.h>

void	parse_scene_elem(t_parser_ctx *ctx, char *line, t_scene *scene)
{
	char	**scene_args;
	int		is_char;

	scene_args = ft_split_set(line, SPACES_CHARS);
	if (!scene_args)
		throw_sys_error("ft_split");
	is_char = ft_strlen(scene_args[0]) == 1;
	if (!scene_args[0])
		(void) NULL;
	else if (is_char && *scene_args[0] == AMBIENT_LIGHT_ID)
		parse_ambient_light(ctx, scene_args, &scene->ambient_light);
	else if (is_char && *scene_args[0] == CAMERA_ID[0])
		parse_camera(ctx, scene_args, &scene->camera);
	else if (is_char && (*scene_args[0] == LIGHT_ID_MANDATORY
			|| *scene_args[0] == LIGHT_ID))
		parse_light(ctx, scene_args, &scene->lights);
	else if (!try_parse_figure(ctx, scene_args, &scene->figures)
		&& *scene_args[0] != '#')
	{
		ft_printff(STDERR_FILENO,
			"Error\nUnknown scene parameter: %s\n", *scene_args);
		exit(EXIT_FAILURE);
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
	mandatory_lights = 0;
	while (lights && mandatory_lights < 2)
	{
		if (lights->type == LIGHT_ID_MANDATORY)
			mandatory_lights++;
		lights = lights->next;
	}
	if (!scene->ambient_light || !mandatory_lights)
		throw_parse_err(ctx, "A mandatory light is missing!");
	else if (mandatory_lights > 1)
		throw_parse_err(ctx, "Only 1 mandatory light (L) is allowed");
}

void	parse_scene_from_str(t_scene *scene, char *str)
{
	int				i;
	int				fd;
	t_parser_ctx	ctx;
	char			**lines;

	ft_bzero(scene, sizeof(t_scene));
	scene->name = get_file_name(str, SCENE_FILE_EXTENSION);
	if (!scene->name)
		throw_sys_error("trying to allocate scene name");
	ctx.filename = "String Literal";
	lines = ft_split(str, '\n');
	if (!lines)
		throw_sys_error("trying to split buffer lines");
	i = 0;
	while (lines[i])
	{
		if (lines[i])
			parse_scene_elem(&ctx, lines[i], scene);
		i++;
	}
	check_parsing(&ctx, scene);
	print_scene(scene);
}

void	parse_scene_from_file(t_scene *scene, char *filename)
{
	int				fd;
	t_parser_ctx	ctx;

	if (!valid_file_extension(filename, SCENE_FILE_EXTENSION))
		throw_parse_err(&ctx, "Only .rt files are allowed");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(filename);
	ft_bzero(scene, sizeof(t_scene));
	scene->name = get_file_name(filename, SCENE_FILE_EXTENSION);
	if (!scene->name)
		throw_sys_error("trying to allocate scene name");
	ctx.filename = filename;
	parse_scene_from_fd(&ctx, fd, scene);
	close(fd);
	check_parsing(&ctx, scene);
	print_scene(scene);
}
