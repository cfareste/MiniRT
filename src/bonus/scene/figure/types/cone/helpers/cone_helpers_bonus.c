/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:27:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"
#include "render/utils/quadratic/quadratic_bonus.h"
#include "render/utils/reference_system/reference_system_bonus.h"
#include <math.h>

static int	calculate_root(t_quadratic_params *params, t_figure *cone,
	t_ray *ray, t_point *center)
{
	float		hr_ratio;
	t_vector	ray_to_cone;

	hr_ratio = cone->co_attrs->height / cone->co_attrs->radius;
	get_vector(center, &ray->origin, &ray_to_cone);
	params->a = ((hr_ratio * hr_ratio) * ((ray->direction.x * ray->direction.x)
				+ (ray->direction.y * ray->direction.y)))
		- (ray->direction.z * ray->direction.z);
	params->b = 2.0 * (hr_ratio * ((hr_ratio * ray->origin.x * ray->direction.x)
				+ (ray->direction.x * center->x)
				+ (hr_ratio * ray->origin.y * ray->direction.y)
				+ (ray->direction.y * center->y))
			- (ray->origin.z * ray->direction.z)
			- (ray->direction.z * center->z));
	params->c = pow(center->x - (hr_ratio * ray->origin.x), 2)
		+ pow(center->y - (hr_ratio * ray->origin.y), 2)
		- pow(center->z - ray->origin.z, 2);
	params->discriminant = (params->b * params->b)
		- (4.0 * params->a * params->c);
	if (params->discriminant < 0.0)
		return (0);
	params->square_root = sqrt(params->discriminant);
	params->roots.close = (-params->b - params->square_root)
		/ (2.0 * params->a);
	return (1);
}

static int	is_invalid_root(float solution, t_bounds *bounds,
	float point_height, t_figure *cone)
{
	return (solution <= bounds->min || solution >= bounds->max
		|| fabs(point_height) > cone->co_attrs->height || point_height < 0.0);
}

int	hit_body_cone(t_figure *cone, t_ray *ray, t_point *center, float *distance)
{
	t_quadratic_params	params;
	t_point				point;

	if (!calculate_root(&params, cone, ray, center))
		return (0);
	translate_point(&ray->origin, &ray->direction, params.roots.close, &point);
	if (is_invalid_root(params.roots.close, &ray->bounds, point.z, cone))
	{
		params.roots.far = (-params.b + params.square_root) / (2.0 * params.a);
		translate_point(&ray->origin, &ray->direction,
			params.roots.far, &point);
		if (is_invalid_root(params.roots.far, &ray->bounds, point.z, cone))
			return (0);
		params.roots.close = params.roots.far;
	}
	if (*distance < params.roots.close)
		return (0);
	*distance = params.roots.close;
	return (1);
}

void	calculate_ideal_normal(t_point *point, t_figure *cone,
	float *refsys_angle, t_vector *res)
{
	t_vector	center_to_point;
	t_vector	projected;
	t_vector	axis;
	float		angle;

	get_vector(point, &cone->position, &center_to_point);
	*refsys_angle = rotate_reference_system(&cone->co_attrs->orientation,
			NULL, &center_to_point);
	projected = center_to_point;
	projected.z = 0;
	normalize(&projected);
	cross(&center_to_point, &projected, &axis);
	normalize(&axis);
	angle = sin(cone->co_attrs->radius
			/ hypot(cone->co_attrs->radius, cone->co_attrs->height));
	rotate_vector(&projected, &axis, angle, res);
	normalize(res);
}
