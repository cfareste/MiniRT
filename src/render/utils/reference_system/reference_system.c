/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/30 19:39:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

float	rotate_reference_system(t_vector *normal, t_vector *vec, t_point *point)
{
	t_vector	ideal;
	t_vector	axis;
	float		angle;

	get_axis(&ideal, BACK);
	if (dot(normal, &ideal) == -1.0)
		get_axis(&axis, UP);
	else
		cross(normal, &ideal, &axis);
	if (axis.x == 0.0 && axis.y == 0.0 && axis.z == 0.0)
		return (0.0);
	normalize(&axis);
	angle = acos(dot(normal, &ideal));
	if (vec)
		rotate_vector(vec, &axis, angle, vec);
	if (point)
		rotate_vector(point, &axis, angle, point);
	return (angle);
}
