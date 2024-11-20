/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:49 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/20 14:43:50 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "scene_settings_parser.h"
#include "parser/helpers/parser_helper.h"

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
	}
	else if (ft_strcmp(args[0], SCENE_SETT_SKY_COLOR) == EQUAL_STRINGS
		&& ensure_params_amount(ctx, args, 1))
		parse_color(ctx, args[1], &settings->sky_color);
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
			throw_parse_err(ctx, ft_strjoin("Unknown scene param: ",
					args[i]));
		i++;
	}
	return (1);
}
