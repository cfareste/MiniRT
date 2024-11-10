/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:25 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 01:45:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"

int		hit_body_cylinder(t_reference_system *refsys, t_figure *cylinder,
			t_ray *ray, float *distance);
