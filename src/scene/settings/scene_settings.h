/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/05 17:31:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/utils/color/color.h"
#include "parser/parser.h"
#include "scene/figure/figure.h"

typedef struct s_scene_settings
{
	char		*name;
	t_color		sky_color;
	t_figure	*sky_box;
}	t_scene_settings;

void	print_scene_settings(t_scene_settings *settings);

void	destroy_scene_settings(t_scene_settings *settings);

void	set_scene_defaults(t_scene_settings *settings, char *filename);