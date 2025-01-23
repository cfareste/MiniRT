/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:06:43 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"

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
