/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:11 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:54:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "float.h"
#include "render/scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"
#include <math.h>

float	get_height(t_point *point, t_point *center, float base)
{
	t_vector	center_to_point;
	float		point_height;
	float		hypotenuse;

	get_vector(point, center, &center_to_point);
	hypotenuse = dot(&center_to_point, &center_to_point);
	point_height = sqrt(hypotenuse - base * base);
	return (point_height);
}

int	belongs_to_base(t_point *point, t_point *center, t_vector *normal,
	float height)
{
	t_vector	top_to_point;
	t_vector	bottom_to_point;
	float		dot_top;
	float		dot_bottom;

	top_to_point.x = point->x - (center->x + (height / 2.0) * normal->x);
	top_to_point.y = point->y - (center->y + (height / 2.0) * normal->y);
	top_to_point.z = point->z - (center->z + (height / 2.0) * normal->z);
	normalize(&top_to_point);
	bottom_to_point.x = point->x - (center->x - (height / 2.0) * normal->x);
	bottom_to_point.y = point->y - (center->y - (height / 2.0) * normal->y);
	bottom_to_point.z = point->z - (center->z - (height / 2.0) * normal->z);
	normalize(&bottom_to_point);
	dot_top = dot(normal, &top_to_point);
	dot_bottom = dot(normal, &bottom_to_point);
	if (fabs(dot_top) > 0.0001 && fabs(dot_bottom) > 0.0001)
		return (0);
	if (fabs(dot_top) < 0.0001)
		return (1);
	else
		return (-1);
}

int	hit_base(t_reference_system *refsys, float base_center_distance,
	float radius, float *distance)
{
	t_figure		plane;
	t_plane_attrs	pl_attrs;
	t_point			base_center;
	t_vector		hit_to_base_center;
	float			base_distance;

	base_distance = FLT_MAX;
	ft_bzero(&pl_attrs, sizeof(t_plane_attrs));
	pl_attrs.orientation.z = 1.0f;
	ft_bzero(&base_center, sizeof(t_point));
	base_center.z = refsys->center.z + base_center_distance;
	set_plane(&plane, &base_center, &pl_attrs);
	if (!plane.hit(&plane, &refsys->ray, &base_distance))
		return (0);
	translate_point(&refsys->ray.origin, &refsys->ray.direction, base_distance,
		&hit_to_base_center);
	get_vector(&hit_to_base_center, &base_center, &hit_to_base_center);
	if (base_distance <= refsys->ray.bounds.min
		|| base_distance >= refsys->ray.bounds.max
		|| sqrt(dot(&hit_to_base_center, &hit_to_base_center)) > radius)
		return (0);
	if (base_distance > *distance)
		return (0);
	*distance = base_distance;
	return (1);
}