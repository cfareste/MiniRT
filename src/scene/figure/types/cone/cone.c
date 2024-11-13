/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/13 20:12:53 by cfidalgo         ###   ########.fr       */
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
		get_axis(&ideal, BACK);
		if (dot(&figure->co_attrs->orientation, &ideal) == -1.0)
			get_axis(&axis, UP);
		else
			cross(&figure->co_attrs->orientation, &ideal, &axis);
		normalize(&axis);
		rotate_vector(res, &axis, -refsys_angle, res);
	}
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	int		is_base;
	t_point	translated_center;
	t_point	rotated_point;

	translate_point(&figure->position, &figure->co_attrs->orientation,
		-figure->co_attrs->height / 2.0, &translated_center);
	get_vector(point, &translated_center, &rotated_point);
	rotate_reference_system(&figure->co_attrs->orientation, NULL,
		&rotated_point);
	is_base = belongs_to_base(point, &figure->position,
			&figure->co_attrs->orientation, figure->co_attrs->height);
	if (is_base)
		get_base_pattern(figure, &rotated_point, figure->co_attrs->radius, res);
	else
		get_cone_body_pattern(figure, &rotated_point, res);
}

t_figure	*parse_cone(t_parser_ctx *ctx, char **parts)
{
	t_figure	*cone;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 3)
		throw_parse_err(ctx, "Missing some cone parameter");
	cone = parse_figure(ctx, parts, FIG_LAST_ATT + 4);
	cone->co_attrs = ft_calloc(1, sizeof(t_cone_attrs));
	if (!cone->co_attrs)
		throw_sys_error("trying to allocate cone attributes");
	cone->print_attrs = print_attrs;
	cone->hit = hit;
	cone->normal = normal;
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&cone->co_attrs->orientation);
	cone->co_attrs->radius = parse_double(ctx, parts[FIG_LAST_ATT + 2]) / 2.0;
	cone->co_attrs->height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	normalize(&cone->co_attrs->orientation);
	translate_point(&cone->position, &cone->co_attrs->orientation,
		-cone->co_attrs->height / 2.0, &cone->position);
	cone->get_color_pattern = get_color;
	check_cone_parsing(ctx, cone);
	return (cone);
}
