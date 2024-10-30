/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/30 21:38:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "render/scene/figure/figure.h"
#include "render/utils/quadratic/quadratic.h"
#include "render/scene/figure/helpers/figure_helpers.h"
#include "render/scene/figure/types/cone/helpers/cone_helpers.h"
#include <math.h>

static void	print_attrs(void *param)
{
	t_cone_attrs	*attrs;

	attrs = (t_cone_attrs *) param;
	printf("%f, %f, %f | %f | %f ",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_reference_system	refsys;
	float				cone_height;
	int					hit;

	refsys.ray.bounds.min = ray->bounds.min;
	refsys.ray.bounds.max = ray->bounds.max;
	get_vector(&ray->origin, &figure->position, &refsys.ray.origin);
	refsys.ray.direction = ray->direction;
	ft_bzero(&refsys.center, sizeof(t_point));
	rotate_reference_system(&figure->co_attrs->orientation,
		&refsys.ray.direction, &refsys.ray.origin);
	cone_height = figure->co_attrs->height;
	hit = hit_base(&refsys, cone_height, figure->co_attrs->radius, distance);
	hit |= hit_body_cone(figure, &refsys.ray, &refsys.center, distance);
	return (hit);
}

static void	normal(t_figure *figure, t_coordinates *point, \
						t_coordinates *res)
{
	t_vector	ideal;
	t_vector	axis;
	float		refsys_angle;

	if (belongs_to_base(point, &figure->position,
			&figure->co_attrs->orientation, figure->co_attrs->height * 2))
	{
		*res = figure->co_attrs->orientation;
		return ;
	}
	calculate_ideal_normal(point, figure, &refsys_angle, res);
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
