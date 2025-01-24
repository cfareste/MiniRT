/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_settings_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:37:03 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/utils/color/color_bonus.h"
#include "scene/figure/figure_bonus.h"

typedef struct s_scene_settings
{
	char		*name;
	t_color		sky_color;
	t_figure	*sky_box;
}	t_scene_settings;

void	print_scene_settings(t_scene_settings *settings);

void	destroy_scene_settings(t_scene_settings *settings);

void	set_scene_defaults(t_scene_settings *settings, char *filename);
