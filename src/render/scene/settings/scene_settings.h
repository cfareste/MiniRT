/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/04 20:49:42 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SCENE_SETTINGS_ID "S"
#define SCENE_SETT_NAME "SN"
#define SCENE_SETT_SKY_COLOR "SSC"
#define SCENE_SETT_SAMPLES "SS"
#define SCENE_SETT_ANTIAL_RAD "SAR"
#define SCENE_SETT_BOKEH_RAD "SBR"
#define SCENE_SETT_MAX_DEPTH "SMD"
#include "render/utils/color/color.h"
#include "parser/parser.h"

typedef struct s_scene_settings
{
	char			*name;
	t_color			sky_color;
	unsigned int	samples;
	double			antialiasing_rad;
	double			bokeh_rad;
	unsigned int	max_depth;
}	t_scene_settings;

void	parse_scene_settings(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);

void	print_scene_settings(t_scene_settings *settings);

void	init_scene_settings(t_scene_settings *settings);

void	destroy_scene_settings(t_scene_settings *settings);