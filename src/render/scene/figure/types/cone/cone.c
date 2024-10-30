/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/30 20:10:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "render/scene/figure/figure.h"
#include "render/utils/quadratic/quadratic.h"
#include "render/scene/figure/helpers/figure_helpers.h"
#include "render/utils/reference_system/reference_system.h"
#include <math.h>

static void	print_attrs(void *param)
{
	t_cone_attrs	*attrs;

	attrs = (t_cone_attrs *) param;
	printf("%f, %f, %f | %f | %f ",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

static int	is_invalid_root(float solution, t_bounds *bounds,
	float point_height, t_figure *cone)
{
	return (solution <= bounds->min || solution >= bounds->max
		|| point_height > cone->co_attrs->height / 2.0);
}

static int	hit_body(t_figure *cone, t_ray *ray, t_point *center, float *distance)
{
	t_quadratic_params	params;
	t_vector			ray_to_cone;
	t_point				point;
	float				point_height;
	float				hr_ratio;

	hr_ratio = cone->co_attrs->height / cone->co_attrs->radius;
	get_vector(center, &ray->origin, &ray_to_cone);
	params.a = ((hr_ratio * hr_ratio) * ((ray->direction.x * ray->direction.x) + (ray->direction.y * ray->direction.y))) - (ray->direction.z * ray->direction.z);
	params.b = 2.0 * (hr_ratio * ((hr_ratio * ray->origin.x * ray->direction.x) + (ray->direction.x * center->x)
		+ (hr_ratio * ray->origin.y * ray->direction.y) + (ray->direction.y * center->y)) - (ray->origin.z * ray->direction.z) - (ray->direction.z * center->z));
	params.c = pow(center->x - (hr_ratio * ray->origin.x), 2) + pow(center->y - (hr_ratio * ray->origin.y), 2) - pow(center->z - ray->origin.z, 2);
	params.discriminant = (params.b * params.b) - (4.0 * params.a * params.c);
	if (params.discriminant < 0.0)
		return (0);
	params.square_root = sqrt(params.discriminant);
	params.roots.close = (-params.b - params.square_root) / (2.0 * params.a);
	translate_point(&ray->origin, &ray->direction, params.roots.close, &point);
	point_height = fabs(point.z - cone->co_attrs->height / 2.0);
	if (is_invalid_root(params.roots.close, &ray->bounds, point_height, cone))
	{
		params.roots.far = (-params.b + params.square_root) / (2.0 * params.a);
		translate_point(&ray->origin, &ray->direction, params.roots.far, &point);
		point_height = fabs(point.z - cone->co_attrs->height / 2.0);
		if (is_invalid_root(params.roots.close, &ray->bounds, point_height, cone))
			return (0);
		params.roots.close = params.roots.far;
	}
	if (*distance < params.roots.close)
		return (0);
	*distance = params.roots.close;
	return (1);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_reference_system	refsys;
	int					hit;

	refsys.ray.bounds.min = ray->bounds.min;
	refsys.ray.bounds.max = ray->bounds.max;
	get_vector(&ray->origin, &figure->position, &refsys.ray.origin);
	refsys.ray.direction = ray->direction;
	ft_bzero(&refsys.center, sizeof(t_point));
	rotate_reference_system(&figure->co_attrs->orientation,
		&refsys.ray.direction, &refsys.ray.origin);
	hit = hit_base(&refsys, figure->co_attrs->height, figure->co_attrs->radius, distance);
	hit |= hit_body(figure, &refsys.ray, &refsys.center, distance);
	return (hit);
}

static void	normal(t_figure *figure, t_coordinates *point, \
						t_coordinates *res)
{
	t_vector	ideal;
	t_vector	axis;
	t_vector	point_to_center;
	t_vector	projected;
	float		refsys_angle;
	float		angle;
	int			is_base;

	is_base = belongs_to_base(point, &figure->position,
		&figure->co_attrs->orientation, figure->co_attrs->height * 2);
	if (is_base == 1)
	{
		*res = figure->co_attrs->orientation;
		return ;
	}
	get_vector(point, &figure->position, &point_to_center);
	refsys_angle = rotate_reference_system(&figure->co_attrs->orientation, NULL, &point_to_center);
	projected = point_to_center;
	projected.z = 0;
	normalize(&projected);
	cross(&point_to_center, &projected, &axis);
	normalize(&axis);
	angle = sin(figure->co_attrs->radius
		/ hypot(figure->co_attrs->radius, figure->co_attrs->height));
	rotate_vector(&projected, &axis, angle, res);
	normalize(res);
	get_axis(&ideal, BACK);
	if (dot(&figure->co_attrs->orientation, &ideal) == -1.0)
		get_axis(&axis, UP);
	else
		cross(&figure->co_attrs->orientation, &ideal, &axis);
	normalize(&axis);
	rotate_vector(res, &axis, -refsys_angle, res);
}

t_figure	*new_cone(char **parts)
{
	t_figure	*cone;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing some cone parameter");
	cone = new_figure(parts[0], parts[1], parts[5]);
	cone->co_attrs = ft_calloc(1, sizeof(t_cone_attrs));
	if (!cone->co_attrs)
		throw_sys_error("trying to allocate cone attributes");
	cone->print_attrs = print_attrs;
	cone->hit = hit;
	cone->normal = normal;
	set_coordinates(parts[2], &cone->co_attrs->orientation);
	cone->co_attrs->radius = ft_atod(parts[3], throw_sys_error,
			"allocating ft_atod in cone radius") / 2.0;
	cone->co_attrs->height = ft_atod(parts[4], throw_sys_error,
			"allocating ft_atod in cone height");
	normalize(&cone->co_attrs->orientation);
	translate_point(&cone->position, &cone->co_attrs->orientation,
		-cone->co_attrs->height / 2.0, &cone->position);
	return (cone);
}
