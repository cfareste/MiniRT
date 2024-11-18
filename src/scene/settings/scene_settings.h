/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/18 17:44:53 by cfidalgo         ###   ########.fr       */
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
	unsigned int	samples;
	int				antialiasing;
	unsigned int	max_depth;
	int				raytracing;
}	t_scene_settings;

void	print_scene_settings(t_scene_settings *settings);

void	init_scene_settings(t_scene_settings *settings);

void	destroy_scene_settings(t_scene_settings *settings);
