/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:49 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 23:42:37 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings_parser.h"
#include "parser/helpers/parser_helper.h"

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
		parse_color(ctx, params[3], &settings->sky_color);
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
	else
		return (0);
	return (1);
}
