/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/05 16:30:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../parser/figure_parser.h"
#include "render/scene/figure/helpers/figure_helpers.h"
#include "render/scene/figure/types/cylinder/helpers/cylinder_helpers.h"
#include "render/utils/vector/parser/vector_parser.h"
#include <math.h>

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

// TODO: Refactor refsys (delete XD)
static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_reference_system	refsys;
	int					hit;
	float				half_height;

	half_height = figure->cy_attrs->height / 2.0;
	refsys.ray.bounds.min = ray->bounds.min;
	refsys.ray.bounds.max = ray->bounds.max;
	get_vector(&ray->origin, &figure->position, &refsys.ray.origin);
	refsys.ray.direction = ray->direction;
	ft_bzero(&refsys.center, sizeof(t_point));
	rotate_reference_system(&figure->cy_attrs->orientation,
		&refsys.ray.direction, &refsys.ray.origin);
	hit = hit_base(&refsys, half_height, figure->cy_attrs->radius, distance);
	hit |= hit_body_cylinder(&refsys, figure, ray, distance);
	hit |= hit_base(&refsys, -half_height, figure->cy_attrs->radius,
			distance);
	return (hit);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	int			is_base;
	float		point_height;
	t_point		center_offset;
	t_vector	center_to_point;

	is_base = belongs_to_base(point, &figure->position,
			&figure->cy_attrs->orientation, figure->cy_attrs->height / 2.0);
	if (is_base == 1)
		*res = figure->cy_attrs->orientation;
	else if (is_base == -1)
		multiply_vector_scalar(&figure->cy_attrs->orientation, -1, res);
	else
	{
		get_vector(point, &figure->position, &center_to_point);
		point_height = get_height(point, &figure->position,
				figure->cy_attrs->radius);
		if (dot(&center_to_point, &figure->cy_attrs->orientation) < 0.0)
			point_height *= -1;
		translate_point(&figure->position, &figure->cy_attrs->orientation,
			point_height, &center_offset);
		get_vector(point, &center_offset, res);
		normalize(res);
	}
}

static void	check_parsing(t_parser_ctx *ctx, t_figure *cylinder)
{
	check_ori_vector_parsing(ctx, &cylinder->cy_attrs->orientation);
	if (cylinder->cy_attrs->radius <= 0)
		throw_parse_err(ctx, "Cylinder diameter must be a positive value");
	else if (cylinder->cy_attrs->height < 0)
		throw_parse_err(ctx, "Cylinder height must be a positive value");
}

t_figure	*parse_cylinder(t_parser_ctx *ctx, char **parts)
{
	t_figure	*cylinder;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 3)
		throw_parse_err(ctx, "Missing some cylinder parameter");
	cylinder = parse_figure(ctx, parts, FIG_LAST_ATT + 4);
	cylinder->cy_attrs = ft_calloc(1, sizeof(t_cylinder_attrs));
	if (!cylinder->cy_attrs)
		throw_sys_error("trying to allocate cylinder attributes");
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&cylinder->cy_attrs->orientation);
	cylinder->cy_attrs->radius = parse_double(ctx,
			parts[FIG_LAST_ATT + 2]) / 2.0f;
	cylinder->cy_attrs->height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	normalize(&cylinder->cy_attrs->orientation);
	cylinder->print_attrs = print_attrs;
	cylinder->hit = hit;
	cylinder->normal = normal;
	check_parsing(ctx, cylinder);
	return (cylinder);
}
