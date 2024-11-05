/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:49 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 13:32:49 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings_parser.h"

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
	return (1);
}
