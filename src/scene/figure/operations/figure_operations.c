/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:04:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 13:13:52 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"

void	rotate_figure(t_vector *vec, t_camera *camera, t_vector *factor)
{
	t_vector	front_projected;

	front_projected = camera->front;
	front_projected.y = 0;
	normalize(&front_projected);
	if (factor->x == 0.0 && factor->y == 0.0 && factor->z == 0.0)
		return ;
	if (factor->x)
		rotate_vector(vec, &camera->right, factor->x, vec);
	if (factor->y)
		rotate_by_world_axis(UP, factor->y, vec);
	if (factor->z)
		rotate_vector(vec, &front_projected, factor->z, vec);
	normalize(vec);
}

void	translate_figure(t_figure *figure, t_camera *camera, t_vector *factor)
{
	t_point		pos;
	t_vector	projected;

	projected = camera->front;
	projected.y = 0.0;
	normalize(&projected);
	pos = figure->position;
	if (factor->x)
		translate_point(&pos, &camera->right, factor->x, &figure->position);
	if (factor->y)
		figure->position.y += factor->y;
	if (factor->z)
		translate_point(&pos, &projected, factor->z, &figure->position);
}
