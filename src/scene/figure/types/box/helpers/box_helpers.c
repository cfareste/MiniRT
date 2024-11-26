/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:14:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 19:22:03 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

static void	set_faces_vectors(t_box_attrs *attrs, t_vector *box_front,
	t_vector *box_right, t_vector *box_up)
{
	attrs->faces[0].orientation = *box_front;
	attrs->faces[0].right = *box_right;
	attrs->faces[0].up = *box_up;
	attrs->faces[1].orientation = *box_right;
	multiply_vector_scalar(box_front, -1, &attrs->faces[1].right);
	attrs->faces[1].up = *box_up;
	attrs->faces[2].orientation = *box_up;
	attrs->faces[2].right = *box_right;
	multiply_vector_scalar(box_front, -1, &attrs->faces[2].up);
	multiply_vector_scalar(box_right, -1, &attrs->faces[3].orientation);
	attrs->faces[3].right = *box_front;
	attrs->faces[3].up = *box_up;
	multiply_vector_scalar(box_up, -1, &attrs->faces[4].orientation);
	attrs->faces[4].right = *box_right;
	attrs->faces[4].up = *box_front;
	multiply_vector_scalar(box_front, -1, &attrs->faces[5].orientation);
	multiply_vector_scalar(box_right, -1, &attrs->faces[5].right);
	attrs->faces[5].up = *box_up;
}

static void	set_faces_dimensions(t_box_attrs *attrs, float width, float height,
	float length)
{
	attrs->faces[0].width = width;
	attrs->faces[0].height = height;
	attrs->faces[1].width = length;
	attrs->faces[1].height = height;
	attrs->faces[2].width = width;
	attrs->faces[2].height = length;
	attrs->faces[3].width = length;
	attrs->faces[3].height = height;
	attrs->faces[4].width = width;
	attrs->faces[4].height = length;
	attrs->faces[5].width = width;
	attrs->faces[5].height = height;
}

void	set_box_faces(t_box_attrs *attrs)
{
	t_vector	box_front;
	t_vector	box_right;
	t_vector	box_up;

	box_front = attrs->faces[0].orientation;
	get_axes(&box_front, &box_right, &box_up);
	set_faces_vectors(attrs, &box_front, &box_right, &box_up);
	set_faces_dimensions(attrs, attrs->width, attrs->height, attrs->length);
}
