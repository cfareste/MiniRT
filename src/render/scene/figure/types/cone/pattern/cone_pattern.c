/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:02:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 21:03:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/scene/figure/figure.h"
#include <math.h>

static float	get_vector_arc_height(t_point *point)
{
	t_vector	point_arc_vector;

	point_arc_vector = *point;
	point_arc_vector.z = 0.0f;
	normalize(&point_arc_vector);
	return (point_arc_vector.y);
}

void	get_cone_body_pattern(t_figure *figure, t_point *point, t_color *res)
{
	float		point_radius;
	float		point_pattern_dimension;
	int			x_index_square;
	int			y_index_square;
	int			pattern_index;

	point_radius = (point->z + (figure->co_attrs->height / 2.0))
		* (figure->co_attrs->radius / figure->co_attrs->height);
	point_pattern_dimension = (2.0 * M_PI * point_radius)
		* (figure->pattern.dimension / (2.0 * M_PI * figure->co_attrs->radius));
	x_index_square = (int)(fabs(
				acos(get_vector_arc_height(point)) * point_radius)
			/ point_pattern_dimension);
	y_index_square = (int)(fabs(point->z) / figure->pattern.dimension);
	if (point->x < 0.0)
		x_index_square++;
	if (point->z < 0.0)
		y_index_square++;
	pattern_index = ((x_index_square % 2) + (y_index_square % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}
