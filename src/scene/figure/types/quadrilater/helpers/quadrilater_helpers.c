/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 13:36:02 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/point/point.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/operations/figure_operations.h"
#include "libft.h"
#include <math.h>

static void	round_point(t_point *point, int precision)
{
	float	factor;

	factor = pow(10, precision);
	while (precision > 2)
	{
		point->x = round(point->x * factor) / factor;
		point->y = round(point->y * factor) / factor;
		point->z = round(point->z * factor) / factor;
		precision--;
	}
}

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
	round_point(rotated_point, 4);
	return (angle);
}

void	rotate_quadrilater(t_figure *quad, t_camera *camera, t_point *factor)
{
	rotate_figure(&quad->qu_attrs->orientation, camera, factor);
	rotate_figure(&quad->qu_attrs->right, camera, factor);
	rotate_figure(&quad->qu_attrs->up, camera, factor);
}
