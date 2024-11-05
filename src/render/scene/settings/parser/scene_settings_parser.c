/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:49 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 15:33:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings_parser.h"

static void	check_parsing(t_parser_ctx *ctx, t_scene_settings *settings)
{
	if (settings->antialiasing_rad < 0)
		throw_parse_err(ctx, "Antialiasing radius must be positive");
	else if (settings->bokeh_rad < 0)
		throw_parse_err(ctx, "Bokeh radius must be positive");
}

void	parse_scene_settings(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings)
{
	int	len;

	len = ft_matrix_len(params);
	if (len > 1)
	{
		free(settings->name);
		settings->name = ft_strdup(params[1]);
	}
	if (len > 2)
		parse_color(ctx, params[2], &settings->sky_color);
	if (len > 3)
		settings->samples = (unsigned int) parse_int(ctx, params[3]);
	if (len > 4)
		settings->antialiasing_rad = parse_double(ctx, params[4]);
	if (len > 5)
		settings->bokeh_rad = parse_double(ctx, params[5]);
	if (len > 6)
		settings->max_depth = (unsigned int) parse_int(ctx, params[6]);
	check_parsing(ctx, settings);
}

int	try_parse_scene_setting(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings)
{
	if (!params[1])
		throw_parse_err(ctx, "Missing param value");
	else if (ft_strcmp(params[0], SCENE_SETTINGS_ID) == EQUAL_STRINGS)
		return (parse_scene_settings(ctx, params, settings), 1);
	else if (ft_strcmp(params[0], SCENE_SETT_NAME) == EQUAL_STRINGS)
	{
		free(settings->name);
		settings->name = ft_strdup(params[1]);
	}
	else if (ft_strcmp(params[0], SCENE_SETT_SKY_COLOR) == EQUAL_STRINGS)
		parse_color(ctx, params[1], &settings->sky_color);
	else if (ft_strcmp(params[0], SCENE_SETT_SAMPLES) == EQUAL_STRINGS)
		settings->samples = (unsigned int) parse_int(ctx, params[1]);
	else if (ft_strcmp(params[0], SCENE_SETT_ANTIAL_RAD) == EQUAL_STRINGS)
		settings->antialiasing_rad = parse_double(ctx, params[1]);
	else if (ft_strcmp(params[0], SCENE_SETT_BOKEH_RAD) == EQUAL_STRINGS)
		settings->bokeh_rad = parse_double(ctx, params[1]);
	else if (ft_strcmp(params[0], SCENE_SETT_MAX_DEPTH) == EQUAL_STRINGS)
		settings->max_depth = (unsigned int) parse_int(ctx, params[1]);
	else
		return (0);
	check_parsing(ctx, settings);
	return (1);
}
