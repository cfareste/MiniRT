/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 00:28:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/scene/figure/figure.h"
#include <math.h>

float	get_vector_arc_height(t_point *point)
{
	t_vector	point_arc_vector;

	point_arc_vector = *point;
	point_arc_vector.z = 0.0f;
	normalize(&point_arc_vector);
	return (point_arc_vector.y);
}

void	get_cylinder_body_pattern(t_figure *figure, t_point *point,
	t_color *res)
{
	int			x_index_square;
	int			y_index_square;
	int			pattern_index;
	float		angle;
	t_vector	point_arc_vector;

	point_arc_vector = *point;
	point_arc_vector.z = 0.0f;
	normalize(&point_arc_vector);
	angle = acos(point_arc_vector.y);
	x_index_square = (int)(fabs(angle * figure->cy_attrs->radius)
			/ figure->pattern.dimension);
	y_index_square = (int)(fabs(point->z) / figure->pattern.dimension);
	if (point->x < 0.0)
		x_index_square++;
	if (point->z < 0.0)
		y_index_square++;
	pattern_index = ((x_index_square % 2) + (y_index_square % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}

void	get_plane_pattern(t_figure *figure, t_point *point, t_color *res)
{
	int	x_index_square;
	int	y_index_square;
	int	pattern_index;

	x_index_square = (int)(fabs(point->x) / figure->pattern.dimension);
	y_index_square = (int)(fabs(point->y) / figure->pattern.dimension);
	if (point->x < 0.0)
		x_index_square++;
	if (point->y < 0.0)
		y_index_square++;
	pattern_index = ((x_index_square % 2) + (y_index_square % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
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
