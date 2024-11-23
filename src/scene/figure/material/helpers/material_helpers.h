/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:21:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/24 00:06:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"

float	get_fresnel_effect(float index, float cos);

void	randomize_ray_direction(t_vector *ideal_bounce_direction,
			t_point *hit_point, uint32_t *seed, t_vector *res);

int		diffuse_scatter(t_render *render, t_scatter_params *params,
			t_color *direct_light, uint32_t *seed);

void	divert_ray_direction(t_vector *ray_dir, float roughness,
			uint32_t *seed, t_vector *res);

int		metallic_scatter(t_render *render, t_scatter_params *params,
			t_color *direct_light, uint32_t *seed);
