/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:18:46 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_parser_bonus.h"
#include "libft.h"
#include "utils/utils_bonus_bonus.h"
#include "parser/helpers/parser_helper_bonus.h"

static void	check_parsing(t_parser_ctx *ctx, t_render *render)
{
	if (render->samples == 0)
		render->samples--;
	if (render->max_depth < 1 || render->max_depth > INT_MAX)
		throw_parse_err(ctx, "Max depth must be greater than 0");
	else if (render->soft_shadows_radius < 0)
		throw_parse_err(ctx, "Soft shadow radius must be a positive value");
}

static int	free_args(char **args)
{
	free_matrix(args);
	return (0);
}

static int	try_parse_render_elem(t_parser_ctx *ctx, char *arg,
				t_render *render)
{
	char	**args;

	args = safe_ft_split(arg, ':',
			throw_sys_error, "trying to split render elem params");
	if (ft_strcmp(args[0], SAMPLES_KEY) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		render->samples = parse_ulong(ctx, args[1]);
	else if (ft_strcmp(args[0], ANTIALIASING_KEY) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		render->antialiasing = parse_int(ctx, args[1]);
	else if (ft_strcmp(args[0], MAX_DEPTH_KEY) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		render->max_depth = parse_int(ctx, args[1]);
	else if (ft_strcmp(args[0], RAYTRACING_KEY) == EQUAL_STRINGS)
		render->strategy.value = RAYTRACING;
	else if (ft_strcmp(args[0], NORMAL_MAP_KEY) == EQUAL_STRINGS)
		render->strategy.value = NORMAL_MAP;
	else if (ft_strcmp(args[0], SOFT_SHADOWS_KEY) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		render->soft_shadows_radius = parse_double(ctx, args[1]);
	else
		return (free_args(args));
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

void	set_render_defaults(t_render *render)
{
	render->samples = -1;
	render->antialiasing = 1;
	render->max_depth = 4;
	render->soft_shadows_radius = 1;
}
