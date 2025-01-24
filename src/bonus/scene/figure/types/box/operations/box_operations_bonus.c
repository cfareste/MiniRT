/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:13:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/operations/figure_operations_bonus.h"
#include "scene/figure/types/box/helpers/box_helpers_bonus.h"

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
