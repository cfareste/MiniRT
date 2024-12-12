/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:13:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 14:47:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/operations/figure_operations.h"
#include "scene/figure/types/box/helpers/box_helpers.h"

void	rotate_box(t_figure *figure, t_camera *camera, t_point *factor)
{
	rotate_figure(&figure->bo_attrs->orientation, camera, factor);
	rotate_figure(&figure->bo_attrs->faces[0].attrs.right, camera, factor);
	rotate_figure(&figure->bo_attrs->faces[0].attrs.up, camera, factor);
}

void	recalculate_box(t_figure *figure)
{
	set_box_faces(figure->bo_attrs, &figure->position);
}
