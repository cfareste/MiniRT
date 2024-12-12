/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 12:54:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/point/point.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/events/figure_events.h"
#include "libft.h"
#include <math.h>

float	get_quad_rotated_point(t_vector *quad_normal, t_vector *quad_right,
	t_point *rotated_point)
{
	float		angle;
	t_vector	right_rotated;

	right_rotated = *quad_right;
	rotate_reference_system(quad_normal, &right_rotated, rotated_point);
	right_rotated.x = ft_fclamp(right_rotated.x, -1.0, 1.0);
	angle = acos(-right_rotated.x);
	if (right_rotated.y > 0.0)
		rotate_by_world_axis(BACK, angle, rotated_point);
	else if (right_rotated.y < 0.0)
		rotate_by_world_axis(BACK, angle * -1, rotated_point);
	rotated_point->x = round(rotated_point->x * 10000.0) / 10000.0;
	rotated_point->y = round(rotated_point->y * 10000.0) / 10000.0;
	rotated_point->z = round(rotated_point->z * 10000.0) / 10000.0;
	return (angle);
}

void	rotate_quadrilater(t_figure *quad, t_camera *camera, t_point *factor)
{
	rotate_figure(&quad->qu_attrs->orientation, camera, factor);
	rotate_figure(&quad->qu_attrs->right, camera, factor);
	rotate_figure(&quad->qu_attrs->up, camera, factor);
}
