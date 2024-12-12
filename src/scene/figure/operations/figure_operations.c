/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:04:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 14:52:23 by arcanava         ###   ########.fr       */
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
	t_vector	projected;

	projected = camera->front;
	projected.y = 0.0;
	normalize(&projected);
	if (factor->x)
		translate_point(&figure->position, &camera->right,
			factor->x, &figure->position);
	if (factor->y)
		figure->position.y += factor->y;
	if (factor->z)
		translate_point(&figure->position, &projected,
			factor->z, &figure->position);
}
