/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:49 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:34 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "scene_settings_parser.h"
#include "parser/helpers/parser_helper.h"
#include <math.h>

void	parse_sky_box(t_parser_ctx *ctx, char *path, t_scene_settings *settings)
{
	t_sphere_attrs	sp_attrs;
	t_point			position;
	t_color			color;

	sp_attrs.radius = 1.0;
	position = wrap_point(0, 0, 0);
	new_color(1.0, 1.0, 1.0, &color);
	if (settings->sky_box)
	{
		free_figures(settings->sky_box);
		settings->sky_box = NULL;
	}
	check_file(ctx, path);
	settings->sky_box = new_sphere(&position, &color, &sp_attrs);
	settings->sky_box->bump_map.texture = get_texture(ctx->textures, path);
}

static int	parse_scene_setting(t_parser_ctx *ctx, char *arg,
			t_scene_settings *settings)
{
	char	**args;

	args = safe_ft_split(arg, ':',
			throw_sys_error, "Splitting scene settings param");
	if (ft_strcmp(args[0], SCENE_SETT_NAME) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
	{
		free(settings->name);
		settings->name = ft_strdup(args[1]);
		if (!settings->name)
			throw_sys_error("Trying to allocate scene name");
	}
	else if (ft_strcmp(args[0], SCENE_SETT_SKY_COLOR) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		parse_color(ctx, args[1], &settings->sky_color);
	else if (ft_strcmp(args[0], SCENE_SETT_SKY_BOX) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		parse_sky_box(ctx, args[1], settings);
	else
	{
		free_matrix(args);
		return (0);
	}
	free_matrix(args);
	return (1);
}

int	try_parse_scene_setting(t_parser_ctx *ctx, char **args,
			t_scene_settings *settings)
{
	int	i;

	if (ft_strcmp(SCENE_SETTINGS_ID, args[0]) != EQUAL_STRINGS)
		return (0);
	i = 1;
	while (args[i])
	{
		if (!parse_scene_setting(ctx, args[i], settings))
			throw_parse_err(ctx, safe_ft_strjoin("Unknown scene param: ",
					args[i], throw_sys_error, "parsing scene settings"));
		i++;
	}
	return (1);
}
