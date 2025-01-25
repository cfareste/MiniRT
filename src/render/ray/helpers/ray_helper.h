/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:21 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ray.h"
#include "utils/iterators/iterators.h"
#include "render/render.h"
#include "render/strategies/shared/strategies_shared.h"

void	set_ray_from_camera(t_ray *ray, t_render *render,
			t_iterators *iterators, uint64_t *seed);

void	set_shadow_ray(t_sample_lights_params *params, t_ray *shadow_ray,
			t_point *origin, t_point *light_pos);
