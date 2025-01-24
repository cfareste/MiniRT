/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:36:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/render.h"
#include "render/utils/hit_record/hit_record.h"

typedef struct s_sample_lights_params
{
	t_render	*render;
	uint64_t	*seed;
}	t_sample_lights_params;

void	sample_lights(t_sample_lights_params *params, t_hit_record *hit_record,
			t_color *color);

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record);
