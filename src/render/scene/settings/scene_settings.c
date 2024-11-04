/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/04 20:37:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene_settings.h"

static void	check_parsing(t_parser_ctx *ctx, t_scene_settings *settings)
{
	if (settings->antialiasing_rad < 0)
		throw_parse_err(ctx, "Antialiasing radius must be positive");
	else if (settings->bokeh_rad < 0)
		throw_parse_err(ctx, "Antialiasing radius must be positive");
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
	print_scene_settings(settings);
}

void	print_scene_settings(t_scene_settings *settings)
{
	printf("Settings: %s | %f, %f, %f | %u | %f | %f | %u\n",
		settings->name,
		settings->sky_color.red, settings->sky_color.green,
		settings->sky_color.blue,
		settings->samples,
		settings->antialiasing_rad,
		settings->bokeh_rad,
		settings->max_depth);
}

void	init_scene_settings(t_scene_settings *settings)
{
	settings->samples = 1;
	settings->max_depth = 1;
}

void	destroy_scene_settings(t_scene_settings *settings)
{
	free(settings->name);
}
