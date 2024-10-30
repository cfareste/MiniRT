/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:31:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/30 21:39:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "render/scene/figure/figure.h"

int		hit_body_cone(t_figure *cone, t_ray *ray, t_point *center,
			float *distance);

void	calculate_ideal_normal(t_point *point, t_figure *cone,
			float *refsys_angle, t_vector *res);
