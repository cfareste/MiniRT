/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:35:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 20:49:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere_pattern.h"
#include <math.h>

static void	get_polar_coordinates(t_point *point, t_figure *sphere,
	t_polar_coordinates *coords)
{
	float		projected_radius;
	t_vector	point_normal;
	t_vector	latitude_normal;

	point_normal = *point;
	latitude_normal = *point;
	latitude_normal.y = 0.0;
	normalize(&latitude_normal);
	projected_radius = sqrt(pow(point->x, 2) + pow(point->z, 2));
	coords->longitude = acos(dot(&point_normal, &latitude_normal))
		* sphere->sp_attrs->radius;
	coords->latitude = acos(-latitude_normal.z) * projected_radius;
}

void	get_sphere_pattern(t_figure *figure, t_point *point, t_color *res)
{
	t_polar_coordinates	coords;
	float				projected_pattern;
	int					pattern_x_index;
	int					pattern_y_index;
	int					pattern_index;

	get_polar_coordinates(point, figure, &coords);
	projected_pattern = sqrt(pow(point->x, 2) + pow(point->z, 2))
		* (figure->pattern.dimension
			/ figure->sp_attrs->radius);
	pattern_x_index = (int)(fabs(coords.latitude) / projected_pattern);
	pattern_y_index = (int)(fabs(coords.longitude) / figure->pattern.dimension);
	if (point->x < 0.0)
		pattern_x_index++;
	if (point->y < 0.0)
		pattern_y_index++;
	pattern_index = ((pattern_x_index % 2) + (pattern_y_index % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}
