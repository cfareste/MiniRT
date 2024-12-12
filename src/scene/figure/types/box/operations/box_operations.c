/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:13:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 22:17:13 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/events/figure_events.h"
#include "scene/figure/types/box/helpers/box_helpers.h"

void	rotate_box(t_figure *figure, t_point *factor)
{
	handle_figure_rotation(&figure->bo_attrs->orientation, factor);
	handle_figure_rotation(&figure->bo_attrs->faces[0].attrs.right, factor);
	handle_figure_rotation(&figure->bo_attrs->faces[0].attrs.up, factor);
}

void	recalculate_box(t_figure *figure)
{
	set_box_faces(figure->bo_attrs, &figure->position);
}
