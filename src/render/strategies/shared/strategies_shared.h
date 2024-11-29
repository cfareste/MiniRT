/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/29 17:24:39 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/scene.h"

typedef struct s_sample_lights_params
{
	t_render	*render;
	uint32_t	*seed;
}	t_sample_lights_params;

void	sample_lights(t_sample_lights_params *params, t_hit_record *hit_record,
			t_material_type scatter_type, t_color *color);

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record);
