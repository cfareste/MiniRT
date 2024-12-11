/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:14:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 18:54:01 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

static void	set_faces_vectors(t_box_attrs *attrs, t_vector *box_front,
	t_vector *box_right, t_vector *box_up)
{
	attrs->faces[0].attrs.orientation = *box_front;
	attrs->faces[0].attrs.right = *box_right;
	attrs->faces[0].attrs.up = *box_up;
	attrs->faces[1].attrs.orientation = *box_right;
	multiply_vector_scalar(box_front, -1, &attrs->faces[1].attrs.right);
	attrs->faces[1].attrs.up = *box_up;
	attrs->faces[2].attrs.orientation = *box_up;
	attrs->faces[2].attrs.right = *box_right;
	multiply_vector_scalar(box_front, -1, &attrs->faces[2].attrs.up);
	multiply_vector_scalar(box_right, -1, &attrs->faces[3].attrs.orientation);
	attrs->faces[3].attrs.right = *box_front;
	attrs->faces[3].attrs.up = *box_up;
	multiply_vector_scalar(box_up, -1, &attrs->faces[4].attrs.orientation);
	attrs->faces[4].attrs.right = *box_right;
	attrs->faces[4].attrs.up = *box_front;
	multiply_vector_scalar(box_front, -1, &attrs->faces[5].attrs.orientation);
	multiply_vector_scalar(box_right, -1, &attrs->faces[5].attrs.right);
	attrs->faces[5].attrs.up = *box_up;
}

static void	set_faces_dimensions(t_box_attrs *attrs, float width, float height,
	float length)
{
	attrs->faces[0].attrs.width = width;
	attrs->faces[0].attrs.height = height;
	attrs->faces[1].attrs.width = length;
	attrs->faces[1].attrs.height = height;
	attrs->faces[2].attrs.width = width;
	attrs->faces[2].attrs.height = length;
	attrs->faces[3].attrs.width = length;
	attrs->faces[3].attrs.height = height;
	attrs->faces[4].attrs.width = width;
	attrs->faces[4].attrs.height = length;
	attrs->faces[5].attrs.width = width;
	attrs->faces[5].attrs.height = height;
}

static void	set_faces_centers(t_box_attrs *attrs, t_point *box_pos)
{
	translate_point(box_pos, &attrs->faces[0].attrs.orientation,
		attrs->length / 2.0, &attrs->faces[0].center);
	translate_point(box_pos, &attrs->faces[1].attrs.orientation,
		attrs->width / 2.0, &attrs->faces[1].center);
	translate_point(box_pos, &attrs->faces[2].attrs.orientation,
		attrs->height / 2.0, &attrs->faces[2].center);
	translate_point(box_pos, &attrs->faces[3].attrs.orientation,
		attrs->width / 2.0, &attrs->faces[3].center);
	translate_point(box_pos, &attrs->faces[4].attrs.orientation,
		attrs->height / 2.0, &attrs->faces[4].center);
	translate_point(box_pos, &attrs->faces[5].attrs.orientation,
		attrs->length / 2.0, &attrs->faces[5].center);
}

void	set_box_faces(t_box_attrs *attrs, t_point *box_pos)
{
	t_vector	box_front;
	t_vector	box_right;
	t_vector	box_up;

	box_front = attrs->orientation;
	box_right = attrs->faces[0].attrs.right;
	box_up = attrs->faces[0].attrs.up;
	set_faces_vectors(attrs, &box_front, &box_right, &box_up);
	set_faces_dimensions(attrs, attrs->width, attrs->height, attrs->length);
	set_faces_centers(attrs, box_pos);
}

int	get_face_index(t_figure *box, t_point *point)
{
	float	box_width_dist;
	float	box_height_dist;
	float	box_length_dist;

	box_width_dist = box->bo_attrs->width / 2.0;
	box_height_dist = box->bo_attrs->height / 2.0;
	box_length_dist = box->bo_attrs->length / 2.0;
	if (point->z == box_length_dist)
		return (0);
	else if (point->x == -box_width_dist)
		return (1);
	else if (point->y == box_height_dist)
		return (2);
	else if (point->x == box_width_dist)
		return (3);
	else if (point->y == -box_height_dist)
		return (4);
	else if (point->z == -box_length_dist)
		return (5);
	else
		return (-1);
}
