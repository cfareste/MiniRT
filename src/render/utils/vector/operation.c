/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 14:43:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/vector/vector.h"

void	cross(t_vector *vec1, t_vector *vec2, t_vector *res)
{
	res->x = (vec1->y * vec2->z) - (vec1->z * vec2->y);
	res->y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	res->z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
}

float	dot(t_vector *vec1, t_vector *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}

void	multiply_vector_scalar(t_vector *vec, float scalar, t_vector *res)
{
	res->x = vec->x * scalar;
	res->y = vec->y * scalar;
	res->z = vec->z * scalar;
}

void	sum_vectors(t_vector *vec1, t_vector *vec2, t_vector *res)
{
	res->x = vec1->x + vec2->x;
	res->y = vec1->y + vec2->y;
	res->z = vec1->z + vec2->z;
}

void	get_axes(t_vector *front, t_vector *right, t_vector *up)
{
	t_vector	world_axis;

	normalize(front);
	get_world_axis(&world_axis, UP);
	if (dot(front, &world_axis) == 1.0)
		get_world_axis(&world_axis, BACK);
	else if (dot(front, &world_axis) == -1.0)
		get_world_axis(&world_axis, FRONT);
	cross(front, &world_axis, right);
	normalize(right);
	cross(right, front, up);
	normalize(up);
}
