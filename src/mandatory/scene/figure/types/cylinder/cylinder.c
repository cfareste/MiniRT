/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:29:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "../../parser/figure_parser.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "scene/figure/types/cylinder/helpers/cylinder_helpers.h"

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

t_figure	*new_cylinder(t_point *pos, t_color *color,
	t_cylinder_attrs *cy_attrs)
{
	t_figure	*cylinder;

	cylinder = new_figure(CYLINDER_ID, pos, color);
	cylinder->cy_attrs = ft_calloc(1, sizeof(t_cylinder_attrs));
	if (!cylinder->cy_attrs)
		throw_sys_error("trying to allocate cylinder attributes");
	cylinder->cy_attrs->orientation = cy_attrs->orientation;
	normalize(&cylinder->cy_attrs->orientation);
	cylinder->cy_attrs->radius = cy_attrs->radius;
	cylinder->cy_attrs->height = cy_attrs->height;
	cylinder->hit = hit;
	cylinder->normal = normal;
	return (cylinder);
}
