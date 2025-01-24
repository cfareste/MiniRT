/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ray_bonus.h"
#include "utils/iterators/iterators_bonus.h"
#include "render/render_bonus.h"
#include "render/strategies/shared/strategies_shared_bonus.h"

void	set_ray_from_camera(t_ray *ray, t_render *render,
			t_iterators *iterators, uint64_t *seed);

void	set_shadow_ray(t_sample_lights_params *params, t_ray *shadow_ray,
			t_point *origin, t_point *light_pos);
