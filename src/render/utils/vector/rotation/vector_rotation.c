/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:56:55 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/22 14:52:14 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/vector/vector.h"
#include "libft.h"
#include <math.h>

void	rotate_x_axis(t_vector *point, double angle)
{
	double	temp_y;
	double	temp_z;

	temp_y = point->y;
	temp_z = point->z;
	point->y = (cos(angle) * temp_y) + (-sin(angle) * temp_z);
	point->z = (sin(angle) * temp_y) + (cos(angle) * temp_z);
}

void	rotate_y_axis(t_vector *point, double angle)
{
	double	temp_x;
	double	temp_z;

	temp_x = point->x;
	temp_z = point->z;
	point->x = (cos(angle) * temp_x) + (sin(angle) * temp_z);
	point->z = (-sin(angle) * temp_x) + (cos(angle) * temp_z);
}

void	rotate_z_axis(t_vector *point, double angle)
{
	double	temp_x;
	double	temp_y;

	temp_x = point->x;
	temp_y = point->y;
	point->x = (cos(angle) * temp_x) + (-sin(angle) * temp_y);
	point->y = (sin(angle) * temp_x) + (cos(angle) * temp_y);
}

void	get_vector_angles(t_vector *vec, double *yaw, double *pitch)
{
	double		yaw_cosine;
	double		pitch_cosine;
	t_vector	projected;

	projected = *vec;
	projected.y = 0.0f;
	normalize(&projected);
	yaw_cosine = ft_clampd(-projected.z, -1.0, 1.0);
	pitch_cosine = ft_clampd(dot(&projected, vec), -1.0, 1.0);
	*yaw = (acos(yaw_cosine) * (180.0f / M_PI));
	*pitch = (acos(pitch_cosine) * (180.0f / M_PI));
	if (vec->x < 0.0)
		*yaw = 360.0 - *yaw;
	if (vec->y < 0.0)
		*pitch *= -1;
}
