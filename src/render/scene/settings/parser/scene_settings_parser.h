/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 15:27:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SCENE_SETT_NAME "SN"
#define SCENE_SETT_SKY_COLOR "SSC"
#define SCENE_SETT_SAMPLES "SS"
#define SCENE_SETT_ANTIAL_RAD "SAR"
#define SCENE_SETT_BOKEH_RAD "SBR"
#define SCENE_SETT_MAX_DEPTH "SMD"

#include "parser/parser.h"
#include "../scene_settings.h"

int		try_parse_scene_setting(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);

void	parse_scene_settings(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);
