/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_disk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:08:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/24 23:20:47 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/helpers/base_attributes/base_attributes.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers.h"

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
