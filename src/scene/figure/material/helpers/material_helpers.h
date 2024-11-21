/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:21:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 13:41:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"

void	randomize_ray_direction(t_vector *ideal_bounce_direction,
			t_point *hit_point, uint32_t *seed, t_vector *res);

void	diffuse_scatter(t_render *render, t_scatter_params *params,
			t_color *direct_light, uint32_t *seed);

void	metallic_scatter(t_render *render, t_scatter_params *params,
			t_color *direct_light, uint32_t *seed);
