/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/05 17:25:28 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SCENE_SETTINGS_ID "S"
#define SCENE_SETT_NAME "name"
#define SCENE_SETT_SKY_COLOR "sky"
#define SCENE_SETT_SKY_BOX "sky_box"

#include "parser/parser.h"
#include "../scene_settings.h"

int		try_parse_scene_setting(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);

void	parse_scene_settings(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);
