/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render.h"

typedef struct s_sample_lights_params
{
	t_render	*render;
	uint64_t	*seed;
}	t_sample_lights_params;

void	sample_lights(t_sample_lights_params *params, t_hit_record *hit_record,
			t_material_type scatter_type, t_color *color);

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record);
