/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_disk_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:08:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/reference_system/reference_system_bonus.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers_bonus.h"

void	get_disk_bump_normal(t_figure *figure, t_point *point, t_vector *res)
{
	t_base_attrs	base_attrs;
	t_point			rotated_point;
	float			angle;

	base_attrs.radius = figure->di_attrs->radius;
	base_attrs.base_distance = 0.0;
	get_vector(point, &figure->position, &rotated_point);
	angle = rotate_reference_system(&figure->di_attrs->orientation, NULL,
			&rotated_point);
	get_base_bump_normal(figure, &rotated_point, &base_attrs, res);
	rotate_by_angle(&figure->di_attrs->orientation, -angle, res);
}
