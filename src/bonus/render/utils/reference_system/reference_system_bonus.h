/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference_system_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:12 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray_bonus.h"
#include "render/utils/point/point_bonus.h"
#include "render/utils/vector/vector_bonus.h"

typedef struct s_reference_system
{
	t_ray	ray;
	t_point	center;
}	t_reference_system;

float	rotate_reference_system(t_vector *normal, t_vector *vec,
			t_point *point);

void	rotate_by_angle(t_vector *normal, float angle, t_vector *res);

void	rotate_by_ideal(t_vector *normal, t_vector *ideal, t_vector *res);

void	rotate_by_world_axis(t_pointing axis_pointing, float angle,
			t_vector *res);
