/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/06 17:30:07 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SCENE_SETT_NAME "SN"
#define SCENE_SETT_SKY_COLOR "SSC"
#define SCENE_SETT_SAMPLES "SS"
#define SCENE_SETT_ANTIALIASING "SAA"
#define SCENE_SETT_MAX_DEPTH "SMD"

#include "parser/parser.h"
#include "../scene_settings.h"

int		try_parse_scene_setting(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);

void	parse_scene_settings(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);
