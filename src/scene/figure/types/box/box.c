/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "scene/figure/types/box/helpers/box_helpers.h"
#include "scene/figure/types/box/pattern/box_pattern.h"
#include "scene/figure/types/quadrilater/helpers/quadrilater_helpers.h"
#include "scene/figure/types/box/operations/box_operations.h"
#include "scene/figure/types/box/composer/box_composer.h"
#include "libft.h"

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
	t_figure	face;
	int			face_index;
	t_point		rotated_point;

	get_vector(point, &figure->position, &rotated_point);
	get_quad_rotated_point(&figure->bo_attrs->orientation,
		&figure->bo_attrs->faces[0].attrs.right, &rotated_point);
	face_index = get_face_index(figure, &rotated_point);
	face.pattern = figure->pattern;
	set_quad(&face, &figure->bo_attrs->faces[face_index].center,
		&figure->bo_attrs->faces[face_index].attrs);
	face.get_color_pattern(&face, point, res);
	add_pattern_offset(figure, face_index, res);
}

t_figure	*new_box(t_point *pos, t_color *color, t_box_attrs *box_attrs)
{
	t_figure	*box;

	box = new_figure(BOX_ID, pos, color);
	box->bo_attrs = ft_calloc(1, sizeof(t_box_attrs));
	if (!box->bo_attrs)
		throw_sys_error("trying to allocate box attributes");
	box->bo_attrs->faces[0].attrs.right = box_attrs->faces[0].attrs.right;
	box->bo_attrs->faces[0].attrs.up = box_attrs->faces[0].attrs.up;
	normalize(&box->bo_attrs->faces[0].attrs.right);
	normalize(&box->bo_attrs->faces[0].attrs.up);
	cross(&box->bo_attrs->faces[0].attrs.right,
		&box->bo_attrs->faces[0].attrs.up, &box->bo_attrs->orientation);
	normalize(&box->bo_attrs->orientation);
	box->bo_attrs->width = box_attrs->width;
	box->bo_attrs->height = box_attrs->height;
	box->bo_attrs->length = box_attrs->length;
	set_box_faces(box->bo_attrs, &box->position);
	box->hit = hit;
	box->normal = normal;
	box->rotate = rotate_box;
	box->compose = compose_box;
	box->recalculate = recalculate_box;
	box->get_color_pattern = get_color;
	return (box);
}
