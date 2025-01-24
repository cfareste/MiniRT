/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:22:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reference_system.h"
#include <math.h>

float	rotate_reference_system(t_vector *normal, t_vector *vec, t_point *point)
{
	t_vector	ideal;
	t_vector	axis;
	float		angle;

	get_world_axis(&ideal, BACK);
	if (dot(normal, &ideal) == -1.0)
		get_world_axis(&axis, UP);
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

void	rotate_by_angle(t_vector *normal, float angle, t_vector *res)
{
	t_vector	ideal;
	t_vector	axis;

	get_world_axis(&ideal, BACK);
	if (dot(normal, &ideal) == -1.0)
		get_world_axis(&axis, UP);
	else
		cross(normal, &ideal, &axis);
	if (axis.x == 0.0 && axis.y == 0.0 && axis.z == 0.0)
		return ;
	normalize(&axis);
	rotate_vector(res, &axis, angle, res);
}

void	rotate_by_ideal(t_vector *normal, t_vector *ideal, t_vector *res)
{
	t_vector	axis;
	float		angle;

	cross(normal, ideal, &axis);
	if (axis.x == 0.0 && axis.y == 0.0 && axis.z == 0.0)
		return ;
	normalize(&axis);
	angle = acos(dot(normal, ideal));
	rotate_vector(res, &axis, angle, res);
}

void	rotate_by_world_axis(t_pointing axis_pointing, float angle,
	t_vector *res)
{
	t_vector	axis;

	get_world_axis(&axis, axis_pointing);
	rotate_vector(res, &axis, angle, res);
}
