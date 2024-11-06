/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:49 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/06 17:30:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings_parser.h"

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
		settings->antialiasing = parse_int(ctx, params[4]);
	if (len > 5)
		settings->max_depth = (unsigned int) parse_int(ctx, params[5]);
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
	else if (ft_strcmp(params[0], SCENE_SETT_ANTIALIASING) == EQUAL_STRINGS)
		settings->antialiasing = parse_int(ctx, params[1]);
	else if (ft_strcmp(params[0], SCENE_SETT_MAX_DEPTH) == EQUAL_STRINGS)
		settings->max_depth = (unsigned int) parse_int(ctx, params[1]);
	else
		return (0);
	return (1);
}
