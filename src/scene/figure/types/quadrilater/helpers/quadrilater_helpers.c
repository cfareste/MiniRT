/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/29 00:11:13 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/point/point.h"
#include "render/utils/reference_system/reference_system.h"
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
	angle = 0.0;
	if (right_rotated.y > 0.0)
	{
		angle = acos(-right_rotated.x);
		rotate_by_axis(BACK, angle, rotated_point);
	}
	else if (right_rotated.y < 0.0)
	{
		angle = -acos(-right_rotated.x);
		rotate_by_axis(BACK, -acos(-right_rotated.x), rotated_point);
	}
	rotated_point->x = round(rotated_point->x * 10000.0) / 10000.0;
	rotated_point->y = round(rotated_point->y * 10000.0) / 10000.0;
	rotated_point->z = round(rotated_point->z * 10000.0) / 10000.0;
	return (angle);
}
