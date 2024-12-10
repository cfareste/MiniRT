/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:53:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 00:52:18 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadrilater.h"
#include "utils/utils_bonus.h"
#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "scene/figure/types/plane/pattern/plane_pattern.h"
#include "scene/figure/types/plane/texture/bump_map_plane.h"
#include "scene/figure/types/quadrilater/parser/quadrilater_parser.h"
#include "scene/figure/types/quadrilater/helpers/quadrilater_helpers.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	float		hit_distance;
	t_vector	center_to_hit;
	float		x_length;
	float		y_length;

	hit_distance = get_plane_center_to_hit(&figure->qu_attrs->orientation,
			&figure->position, ray, &center_to_hit);
	if (hit_distance < 0.0 || *distance <= hit_distance)
		return (0);
	x_length = dot(&center_to_hit, &figure->qu_attrs->right);
	y_length = dot(&center_to_hit, &figure->qu_attrs->up);
	if (fabs(x_length) > figure->qu_attrs->width / 2.0
		|| fabs(y_length) > figure->qu_attrs->height / 2.0)
		return (0);
	*distance = hit_distance;
	return (1);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	t_point		rotated_point;
	float		quad_angle;
	float		second_angle;

	if (!figure->bump_map.texture)
	{
		*res = figure->qu_attrs->orientation;
		return ;
	}
	get_vector(point, &figure->position, &rotated_point);
	quad_angle = rotate_reference_system(&figure->qu_attrs->orientation,
			NULL, NULL);
	second_angle = get_quad_rotated_point(&figure->qu_attrs->orientation,
			&figure->qu_attrs->right, &rotated_point);
	get_plane_bump_normal(figure, &rotated_point, res);
	rotate_by_axis(BACK, -second_angle, res);
	rotate_by_angle(&figure->qu_attrs->orientation, -quad_angle, res);
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	t_point	rotated_point;

	get_vector(point, &figure->position, &rotated_point);
	get_quad_rotated_point(&figure->qu_attrs->orientation,
		&figure->qu_attrs->right, &rotated_point);
	get_plane_pattern(figure, &rotated_point, res);
}

void	set_quad(t_figure *quad, t_point *position, t_quadrilater_attrs *attrs)
{
	quad->qu_attrs = attrs;
	quad->position = *position;
	quad->hit = hit;
	quad->normal = normal;
	quad->rotate = rotate_quadrilater;
	quad->get_color_pattern = get_color;
}

t_figure	*new_quadrilater(t_point *pos, t_color *color,
	t_quadrilater_attrs *quad_attrs)
{
	t_figure	*quad;

	quad = new_figure(QUAD_ID, pos, color);
	quad->qu_attrs = ft_calloc(1, sizeof(t_quadrilater_attrs));
	if (!quad->qu_attrs)
		throw_sys_error("trying to allocate quad attributes");
	quad->qu_attrs->width = quad_attrs->width;
	quad->qu_attrs->height = quad_attrs->height;
	quad->qu_attrs->orientation = quad_attrs->orientation;
	get_axes(&quad->qu_attrs->orientation, &quad->qu_attrs->right,
		&quad->qu_attrs->up);
	quad->hit = hit;
	quad->normal = normal;
	quad->rotate = rotate_quadrilater;
	quad->get_color_pattern = get_color;
	return (quad);
}
