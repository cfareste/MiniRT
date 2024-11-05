/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:25 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 13:26:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"

int		hit_body_cylinder(t_reference_system *refsys, t_figure *cylinder, t_ray *ray,
			float *distance);
