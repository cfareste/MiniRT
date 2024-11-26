/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 14:43:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "utils/utils_bonus.h"
#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/figure/types/box/parser/box_parser.h"
#include "libft.h"

static void	print_attrs(void *param)
{
	t_box_attrs	*attrs;

	attrs = param;
	printf("%f, %f, %f | %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->width, attrs->height, attrs->length);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	(void) figure;
	(void) ray;
	(void) distance;
	return (0);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	(void) figure;
	(void) point;
	(void) res;
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	(void) figure;
	(void) point;
	(void) res;
}

t_figure	*parse_box(t_parser_ctx *ctx, char **parts)
{
	t_figure	*box;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 4)
		throw_parse_err(ctx, "Missing some box parameter");
	box = parse_figure(ctx, parts, FIG_LAST_ATT + 5);
	box->bo_attrs = ft_calloc(1, sizeof(t_box_attrs));
	if (!box->bo_attrs)
		throw_sys_error("trying to allocate box attributes");
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&box->bo_attrs->orientation);
	box->bo_attrs->width = parse_double(ctx, parts[FIG_LAST_ATT + 2]);
	box->bo_attrs->height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	box->bo_attrs->length = parse_double(ctx, parts[FIG_LAST_ATT + 4]);
	normalize(&box->bo_attrs->orientation);
	box->print_attrs = print_attrs;
	box->hit = hit;
	box->normal = normal;
	box->get_color_pattern = get_color;
	check_box_parsing(ctx, box);
	get_axes(&box->bo_attrs->orientation, &box->bo_attrs->right,
		&box->bo_attrs->up);
	return (box);
}
