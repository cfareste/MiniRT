/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/27 21:58:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "utils/utils_bonus.h"
#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/figure/types/box/parser/box_parser.h"
#include "scene/figure/types/box/helpers/box_helpers.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/types/quadrilater/helpers/quadrilater_helpers.h"
#include "libft.h"
#include <math.h>

static void	print_attrs(void *param)
{
	t_box_attrs	*attrs;

	attrs = param;
	printf("%f, %f, %f | %f | %f | %f",
		attrs->faces[0].attrs.orientation.x,
		attrs->faces[0].attrs.orientation.y,
		attrs->faces[0].attrs.orientation.z,
		attrs->width, attrs->height, attrs->length);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	int			i;
	float		face_distance;
	t_figure	face;

	i = 0;
	face_distance = FLT_MAX;
	while (i < 6)
	{
		set_quad(&face, &figure->bo_attrs->faces[i].center,
			&figure->bo_attrs->faces[i].attrs);
		face.hit(&face, ray, &face_distance);
		i++;
	}
	if (face_distance >= *distance)
		return (0);
	*distance = face_distance;
	return (1);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	t_figure	face;
	int			index_face;
	t_point		rotated_point;

	get_vector(point, &figure->position, &rotated_point);
	get_quad_rotated_point(&figure->bo_attrs->orientation,
		&figure->bo_attrs->faces[0].attrs.right, &rotated_point);
	index_face = get_face_index(figure, &rotated_point);
	face.bump_map = figure->bump_map;
	set_quad(&face, &figure->bo_attrs->faces[index_face].center,
		&figure->bo_attrs->faces[index_face].attrs);
	face.normal(&face, point, res);
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
	normalize(&box->bo_attrs->orientation);
	box->bo_attrs->width = parse_double(ctx, parts[FIG_LAST_ATT + 2]);
	box->bo_attrs->height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	box->bo_attrs->length = parse_double(ctx, parts[FIG_LAST_ATT + 4]);
	box->print_attrs = print_attrs;
	box->hit = hit;
	box->normal = normal;
	box->get_color_pattern = get_color;
	check_box_parsing(ctx, box);
	set_box_faces(box->bo_attrs, &box->position);
	return (box);
}
