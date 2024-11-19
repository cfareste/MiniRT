/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:21 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 22:13:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "parser.h"
#include "scene/scene.h"
#include "window/window.h"
#include "scene/parser/scene_parser.h"
#include "parser/helpers/parser_helper.h"
#include "render/parser/render_parser.h"
#include <fcntl.h>

static void	check_parsing(t_parser_ctx *ctx, t_window *window)
{
	check_scene_parsing(ctx, &window->render.scene);
}

void	parse_line(t_parser_ctx *ctx, char *line, t_window *window)
{

	char	**args;

	args = ft_split_set(line, SPACES_CHARS);
	if (!args)
		throw_sys_error("ft_split");
	if (args[0] && *args[0] != '#')
	{
		if (!try_parse_scene_elems(ctx, args, &window->render.scene))
			if (!try_parse_render_elems(ctx, args, &window->render))
			throw_parse_err(ctx, ft_strjoin("Unknown parameter: ", *args));
	}
	free_matrix(args);
}

void	parse_from_fd(t_parser_ctx *ctx, int fd, t_window *window)
{
	char	*line;

	ctx->line = 1;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (*line)
			parse_line(ctx, line, window);
		free(line);
		ctx->line++;
		line = get_next_line(fd, 0);
	}
}

void	parse(t_window *window, char *filename)
{
	int				fd;
	t_parser_ctx	ctx;

	window->filename = filename;
	pthread_mutex_init(&window->render.scene.mutex, NULL);
	ctx.textures = &window->textures;
	ctx.filename = window->filename;
	ctx.line = 0;
	if (!correct_file_extension(window->filename, SCENE_FILE_EXTENSION))
		throw_parse_err(&ctx, "Only .rt files are allowed");
	fd = open(window->filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(window->filename);
	init_render_opts(&window->render);
	window->render.scene.settings.name = get_file_name(window->filename, SCENE_FILE_EXTENSION);
	if (!window->render.scene.settings.name)
		throw_sys_error("trying to allocate scene name");
	parse_from_fd(&ctx, fd, window);
	close(fd);
	check_parsing(&ctx, window);
}
