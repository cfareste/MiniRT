/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/13 21:43:06 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern_helpers.h"
#include "libft.h"
#include <math.h>

void	get_base_pattern(t_figure *figure, t_point *point, t_base_attrs *attrs,
	t_color *res)
{
	t_point_params	params;
	t_vector		point_to_base;
	int				pattern_x_index;
	int				pattern_y_index;
	int				pattern_index;

	point_to_base = *point;
	point_to_base.z = 0.0;
	params.point_radius = sqrt(dot(&point_to_base, &point_to_base));
	params.point_base_height = attrs->radius - params.point_radius;
	normalize(&point_to_base);
	params.point_pattern_dim = params.point_radius
		* (figure->pattern.dimension / attrs->radius);
	point_to_base.y = ft_fclamp(point_to_base.y, -1.0, 1.0);
	pattern_x_index = (int)(fabs(acos(point_to_base.y) * params.point_radius)
			/ params.point_pattern_dim);
	pattern_y_index = (int)(fabs(params.point_base_height
				+ attrs->base_distance) / figure->pattern.dimension);
	if (point->x > 0.0)
		pattern_x_index++;
	if (point->z > 0.0)
		pattern_y_index++;
	pattern_index = ((pattern_x_index % 2) + (pattern_y_index % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}
