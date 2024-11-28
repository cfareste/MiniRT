/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:18:46 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/28 18:25:19 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render_parser.h"
#include "utils/utils_bonus.h"
#include "parser/helpers/parser_helper.h"
#include <limits.h>

static void	check_parsing(t_parser_ctx *ctx, t_render *render)
{
	if (render->samples < 1 || render->samples > INT_MAX)
		throw_parse_err(ctx, "At least 1 sample is required");
	else if (render->max_depth < 1 || render->max_depth > INT_MAX)
		throw_parse_err(ctx, "Max depth must be greater than 0");
}

static int	try_parse_render_elem(t_parser_ctx *ctx, char *arg,
				t_render *render)
{
	char	**args;

	args = safe_ft_split(arg, ':',
			throw_sys_error, "trying to split render elem params");
	if (ft_strcmp(args[0], SAMPLES_KEY) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		render->samples = parse_int(ctx, args[1]);
	else if (ft_strcmp(args[0], ANTIALIASING_KEY) == EQUAL_STRINGS)
		render->antialiasing = 1;
	else if (ft_strcmp(args[0], MAX_DEPTH_KEY) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		render->max_depth = parse_int(ctx, args[1]);
	else if (ft_strcmp(args[0], RAYTRACING_KEY) == EQUAL_STRINGS)
		render->strategy = RAYTRACING;
	else if (ft_strcmp(args[0], NORMAL_MAP_KEY) == EQUAL_STRINGS)
		render->strategy = NORMAL_MAP;
	else
	{
		free_matrix(args);
		return (0);
	}
	free_matrix(args);
	check_parsing(ctx, render);
	return (1);
}

int	try_parse_render_elems(t_parser_ctx *ctx, char **args,
				t_render *render)
{
	int	i;

	if (ft_strcmp(RENDER_PARSE_ID, args[0]) != EQUAL_STRINGS)
		return (0);
	i = 1;
	while (args[i])
	{
		if (!try_parse_render_elem(ctx, args[i], render))
			throw_parse_err(ctx, ft_strjoin("Unknown render param: ",
					args[i]));
		i++;
	}
	return (1);
}
