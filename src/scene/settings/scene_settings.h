/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 22:13:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SCENE_SETTINGS_ID "S"
#include "render/utils/color/color.h"
#include "parser/parser.h"

typedef struct s_scene_settings
{
	char			*name;
	t_color			sky_color;
}	t_scene_settings;

void	print_scene_settings(t_scene_settings *settings);

void	destroy_scene_settings(t_scene_settings *settings);
