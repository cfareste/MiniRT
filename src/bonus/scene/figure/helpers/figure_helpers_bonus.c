/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_helpers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:11 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene/figure/figure_bonus.h"
#include "render/utils/reference_system/reference_system_bonus.h"
#include <math.h>

float	get_height(t_point *point, t_point *center, float base)
{
	t_vector	center_to_point;
	float		point_height;
	float		hypotenuse;

	get_vector(point, center, &center_to_point);
	hypotenuse = dot(&center_to_point, &center_to_point);
	point_height = sqrt(fabs(hypotenuse - base * base));
	return (point_height);
}

int	belongs_to_base(t_point *point, t_point *center, t_vector *normal,
	float base_height)
{
	t_vector	top_to_point;
	t_vector	bottom_to_point;
	float		dot_top;
	float		dot_bottom;

	top_to_point.x = point->x - (center->x + base_height * normal->x);
	top_to_point.y = point->y - (center->y + base_height * normal->y);
	top_to_point.z = point->z - (center->z + base_height * normal->z);
	normalize(&top_to_point);
	bottom_to_point.x = point->x - (center->x - base_height * normal->x);
	bottom_to_point.y = point->y - (center->y - base_height * normal->y);
	bottom_to_point.z = point->z - (center->z - base_height * normal->z);
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

float	get_plane_center_to_hit(t_vector *normal, t_point *center, t_ray *ray,
	t_vector *center_to_hit)
{
	t_point			hit_point;
	t_figure		plane;
	t_plane_attrs	plane_attrs;
	float			hit_distance;

	hit_distance = FLT_MAX;
	plane_attrs.orientation = *normal;
	set_plane(&plane, center, &plane_attrs);
	if (!plane.hit(&plane, ray, &hit_distance)
		|| hit_distance >= ray->bounds.max || hit_distance <= ray->bounds.min)
		return (-1);
	translate_point(&ray->origin, &ray->direction, hit_distance, &hit_point);
	get_vector(&hit_point, center, center_to_hit);
	return (hit_distance);
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

void	get_figure_color(t_figure *figure, t_point *point, t_color *res)
{
	if (figure->pattern.dimension == 0)
		*res = figure->color;
	else
		figure->get_color_pattern(figure, point, res);
}
