/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 12:54:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../parser/figure_parser.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "scene/figure/figure.h"
#include "render/utils/quadratic/quadratic.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "scene/figure/types/cone/parser/cone_parser.h"
#include "scene/figure/types/cone/helpers/cone_helpers.h"
#include "scene/figure/pattern/helpers/pattern_helpers.h"
#include "scene/figure/types/cone/pattern/cone_pattern.h"
#include "scene/figure/types/cone/texture/bump_map_cone.h"
#include "scene/figure/events/figure_events.h"
#include "parser/helpers/parser_helper.h"
#include <math.h>

static void	rotate(t_figure *figure, t_camera *camera, t_point *factor)
{
	t_point		*pos;
	t_vector	*dir;

	pos = &figure->position;
	dir = &figure->co_attrs->orientation;
	translate_point(pos, dir, figure->co_attrs->height / 2.0, pos);
	rotate_figure(&figure->co_attrs->orientation, camera, factor);
	translate_point(pos, dir, -figure->co_attrs->height / 2.0, pos);
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
	int			is_base;
	float		refsys_angle;

	is_base = belongs_to_base(point, &figure->position,
			&figure->co_attrs->orientation, figure->co_attrs->height);
	if (figure->bump_map.texture)
		get_cone_bump_normal(figure, point, is_base, res);
	else if (is_base)
		*res = figure->co_attrs->orientation;
	else
	{
		calculate_ideal_normal(point, figure, &refsys_angle, res);
		get_world_axis(&ideal, BACK);
		if (dot(&figure->co_attrs->orientation, &ideal) == -1.0)
			get_world_axis(&axis, UP);
		else
			cross(&figure->co_attrs->orientation, &ideal, &axis);
		normalize(&axis);
		rotate_vector(res, &axis, -refsys_angle, res);
	}
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	int				is_base;
	t_point			rotated_point;
	t_base_attrs	base_attrs;

	base_attrs.radius = figure->co_attrs->radius;
	base_attrs.base_distance = figure->co_attrs->height;
	get_vector(point, &figure->position, &rotated_point);
	rotate_reference_system(&figure->co_attrs->orientation, NULL,
		&rotated_point);
	is_base = belongs_to_base(point, &figure->position,
			&figure->co_attrs->orientation, figure->co_attrs->height);
	if (is_base)
		get_base_pattern(figure, &rotated_point, &base_attrs, res);
	else
		get_cone_body_pattern(figure, &rotated_point, res);
}

t_figure	*new_cone(t_point *pos, t_color *color, t_cone_attrs *co_attrs)
{
	t_figure	*cone;

	translate_point(pos, &co_attrs->orientation, -co_attrs->height / 2.0, pos);
	cone = new_figure(CONE_ID, pos, color);
	cone->co_attrs = ft_calloc(1, sizeof(t_cone_attrs));
	if (!cone->co_attrs)
		throw_sys_error("trying to allocate cone attributes");
	cone->co_attrs->orientation = co_attrs->orientation;
	normalize(&cone->co_attrs->orientation);
	cone->co_attrs->radius = co_attrs->radius;
	cone->co_attrs->height = co_attrs->height;
	cone->hit = hit;
	cone->normal = normal;
	cone->rotate = rotate;
	cone->get_color_pattern = get_color;
	return (cone);
}
