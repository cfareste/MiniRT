/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/16 18:10:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ray.h"
#include "scene/camera/camera.h"
#include "utils/iterators/iterators.h"
#include "render/render_bonus.h"
#include "render/strategies/shared/strategies_shared.h"

void	set_ray_from_camera(t_ray *ray, t_render *render,
			t_iterators *iterators, uint64_t *seed);

void	set_shadow_ray(t_sample_lights_params *params, t_ray *shadow_ray,
			t_point *origin, t_point *light_pos);
