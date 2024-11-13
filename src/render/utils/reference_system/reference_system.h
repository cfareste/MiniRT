/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference_system.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:12 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/12 23:32:56 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"

typedef struct s_reference_system
{
	t_ray	ray;
	t_point	center;
}	t_reference_system;

float	rotate_reference_system(t_vector *normal, t_vector *vec,
			t_point *point);

void	rotate_by_angle(t_vector *normal, float angle, t_vector *res);

void	rotate_by_ideal(t_vector *normal, t_vector *ideal, t_vector *res);
