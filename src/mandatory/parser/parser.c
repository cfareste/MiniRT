/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:21 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 16:01:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parser.h"
#include "libft.h"
#include "utils/utils.h"
#include "scene/parser/scene_parser.h"
#include "parser/helpers/parser_helper.h"
#include <fcntl.h>

static void	check_parsing(t_parser_ctx *ctx, t_window *window)
{
	check_scene_parsing(ctx, &window->render.scene);
}

void	parse_line(t_parser_ctx *ctx, char *line, t_window *window)
{
	char	**splitted_by_comment;
	char	**args;

	if (*line == '#')
		return ;
	splitted_by_comment = ft_split(line, '#');
	if (!splitted_by_comment)
		throw_sys_error("ft_split");
	args = ft_split_set(splitted_by_comment[0], SPACES_CHARS);
	if (!args)
		throw_sys_error("ft_split");
	if (args[0])
	{
		if (!try_parse_scene_elems(ctx, args, &window->render.scene))
			throw_parse_err(ctx, safe_ft_strjoin("Unknown parameter: ", *args,
					throw_sys_error, "ft_strjoin"));
	}
	free_matrix(args);
	free_matrix(splitted_by_comment);
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

	window->filename = ft_strdup(filename);
	if (!window->filename)
		throw_sys_error("Allocating filename");
	ctx.filename = window->filename;
	ctx.line = 0;
	if (!correct_file_extension(window->filename, FILE_EXTENSION))
		throw_parse_err(&ctx, "Only .rt files are allowed");
	fd = open(window->filename, O_RDONLY);
	if (fd == -1)
		throw_sys_error(window->filename);
	parse_from_fd(&ctx, fd, window);
	close(fd);
	check_parsing(&ctx, window);
}
