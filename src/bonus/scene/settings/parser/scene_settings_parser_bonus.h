/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:33 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SCENE_SETTINGS_ID "S"
#define SCENE_SETT_NAME "name"
#define SCENE_SETT_SKY_COLOR "sky"
#define SCENE_SETT_SKY_BOX "sky_box"

#include "parser/parser_bonus.h"
#include "../scene_settings_bonus.h"

int		try_parse_scene_setting(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);
