/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:00:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/11 00:52:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "libft.h"
#include <math.h>

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
	point_arc_vector.y = ft_fclamp(point_arc_vector.y, -1.0, 1.0);
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
