/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:53:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

typedef struct s_bounds
{
	float	max;
	float	min;
}	t_bounds;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
	t_bounds	bounds;
}	t_ray;

void	set_ray(t_ray *ray, t_point *origin, t_vector *direction);
