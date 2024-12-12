/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:13:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 12:05:28 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/events/figure_events.h"
#include "scene/figure/types/box/helpers/box_helpers.h"

void	rotate_box(t_figure *figure, t_camera *camera, t_point *factor)
{
	handle_figure_rotation(&figure->bo_attrs->orientation, camera, factor);
	handle_figure_rotation(&figure->bo_attrs->faces[0].attrs.right, camera,
		factor);
	handle_figure_rotation(&figure->bo_attrs->faces[0].attrs.up, camera,
		factor);
}

void	recalculate_box(t_figure *figure)
{
	set_box_faces(figure->bo_attrs, &figure->position);
}
