/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:02:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/13 20:27:02 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "libft.h"
#include <math.h>

static float	get_vector_arc_height(t_point *point)
{
	t_vector	point_arc_vector;

	point_arc_vector = *point;
	point_arc_vector.z = 0.0f;
	normalize(&point_arc_vector);
	return (ft_fclamp(point_arc_vector.y, -1.0, 1.0));
}

void	get_cone_body_pattern(t_figure *figure, t_point *point, t_color *res)
{
	float		point_radius;
	float		point_pattern_dimension;
	int			x_index_square;
	int			y_index_square;
	int			pattern_index;

	point_radius = point->z
		* (figure->co_attrs->radius / figure->co_attrs->height);
	point_pattern_dimension = point_radius
		* (figure->pattern.dimension / (figure->co_attrs->radius));
	x_index_square = (int)(fabs(
				acos(get_vector_arc_height(point)) * point_radius)
			/ point_pattern_dimension);
	y_index_square = (int)(point->z / figure->pattern.dimension);
	if (point->x < 0.0)
		x_index_square++;
	if (point->z < 0.0)
		y_index_square++;
	pattern_index = ((x_index_square % 2) + (y_index_square % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}
