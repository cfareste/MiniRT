/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_parser.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/05 13:32:41 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parser/parser.h"
#include "../scene_settings.h"

int	try_parse_scene_setting(t_parser_ctx *ctx, char **params,
		t_scene_settings *settings);
