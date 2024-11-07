/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 13:26:39 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render/scene/figure/figure.h"
#include "render/utils/quadratic/quadratic.h"
#include "render/scene/figure/helpers/figure_helpers.h"
#include <math.h>

static int	calculate_intersections(t_quadratic_params *params,
	t_reference_system *refsys, float radius)
{
	t_vector	ray_to_cylinder;

	get_vector(&refsys->center, &refsys->ray.origin, &ray_to_cylinder);
	ray_to_cylinder.z = 0;
	params->a = (refsys->ray.direction.x * refsys->ray.direction.x)
		+ (refsys->ray.direction.y * refsys->ray.direction.y);
	params->b = -2.0 * ((refsys->ray.direction.x * ray_to_cylinder.x)
			+ (refsys->ray.direction.y * ray_to_cylinder.y));
	params->c = (ray_to_cylinder.x * ray_to_cylinder.x)
		+ (ray_to_cylinder.y * ray_to_cylinder.y) - (pow(radius, 2));
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
	float point_height, t_figure *cylinder)
{
	return (solution <= bounds->min || solution >= bounds->max
		|| point_height > cylinder->cy_attrs->height / 2.0);
}

int	hit_body_cylinder(t_reference_system *refsys, t_figure *cy, t_ray *ray,
	float *distance)
{
	t_quadratic_params	params;
	t_point				point;
	float				point_height;

	if (!calculate_intersections(&params, refsys, cy->cy_attrs->radius))
		return (0);
	translate_point(&refsys->ray.origin, &refsys->ray.direction,
		params.roots.close, &point);
	point_height = get_height(&point, &refsys->center, cy->cy_attrs->radius);
	if (is_invalid_root(params.roots.close, &ray->bounds, point_height, cy))
	{
		params.roots.far = (-params.b + params.square_root) / (2.0 * params.a);
		translate_point(&refsys->ray.origin, &refsys->ray.direction,
			params.roots.far, &point);
		point_height = get_height(&point, &refsys->center,
				cy->cy_attrs->radius);
		if (is_invalid_root(params.roots.far, &ray->bounds, point_height, cy))
			return (0);
		params.roots.close = params.roots.far;
	}
	if (*distance < params.roots.close)
		return (0);
	*distance = params.roots.close;
	return (1);
}
