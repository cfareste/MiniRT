/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:53:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 23:49:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadrilater.h"
#include "utils/utils_bonus.h"
#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "scene/figure/types/quadrilater/parser/quadrilater_parser.h"
#include "scene/figure/types/quadrilater/helpers/quadrilater_helpers.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

static void	print_attrs(void *param)
{
	t_quadrilater_attrs	*attrs;

	attrs = param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->width, attrs->height);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	float		hit_distance;
	t_vector	center_to_hit;
	float		x_length;
	float		y_length;

	hit_distance = get_plane_center_to_hit(&figure->qu_attrs->orientation,
			&figure->position, ray, &center_to_hit);
	if (hit_distance < 0.0)
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
	(void) point;
	*res = figure->qu_attrs->orientation;
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	(void) figure;
	(void) point;
	(void) res;
}

t_figure	*parse_quadrilater(t_parser_ctx *ctx, char **parts)
{
	t_figure	*quadrilater;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 3)
		throw_parse_err(ctx, "Missing some quadrilater parameter");
	quadrilater = parse_figure(ctx, parts, FIG_LAST_ATT + 4);
	quadrilater->qu_attrs = ft_calloc(1, sizeof(t_quadrilater_attrs));
	if (!quadrilater->qu_attrs)
		throw_sys_error("trying to allocate quadrilater attributes");
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&quadrilater->qu_attrs->orientation);
	quadrilater->qu_attrs->width = parse_double(ctx, parts[FIG_LAST_ATT + 2]);
	quadrilater->qu_attrs->height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	normalize(&quadrilater->qu_attrs->orientation);
	quadrilater->print_attrs = print_attrs;
	quadrilater->hit = hit;
	quadrilater->normal = normal;
	quadrilater->get_color_pattern = get_color;
	check_quadrilater_parsing(ctx, quadrilater);
	set_quadrilater_vectors(quadrilater);
	return (quadrilater);
}
