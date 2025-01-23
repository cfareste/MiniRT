/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:59 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 20:06:07 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_helper.h"
#include "libft.h"
#include "render/utils/vector/rotation/vector_rotation.h"
#include "render/utils/reference_system/reference_system.h"
#include <math.h>

void	update_camera_fov(t_camera *camera, int factor)
{
	if (!factor)
		return ;
	camera->fov = ft_clampd(camera->fov + factor, 0, 180);
}

void	update_camera_pos(t_camera *camera, t_point factor)
{
	t_vector	front_dir;

	if (factor.x)
		translate_point(&camera->position, &camera->right, factor.x,
			&camera->position);
	if (factor.y)
		camera->position.y += factor.y;
	if (factor.z)
	{
		front_dir = camera->front;
		front_dir.y = 0.0;
		normalize(&front_dir);
		camera->position.x += front_dir.x * factor.z;
		camera->position.z += front_dir.z * factor.z;
	}
}

void	update_camera_focus_dis(t_camera *camera, double factor)
{
	if (!factor)
		return ;
	camera->focus_dist = ft_clampd(
			camera->focus_dist + (factor * 0.2), 1, DBL_MAX);
}

void	update_camera_defocus_rad(t_camera *camera, double factor)
{
	if (!factor)
		return ;
	camera->defocus = ft_clampd(
			camera->defocus + (factor * 0.2), 0, DBL_MAX);
	calculate_defocus_components(camera);
}

void	update_camera_front(t_camera *camera, t_point factor)
{
	double	yaw;
	double	pitch;

	get_vector_angles(&camera->front, &yaw, &pitch);
	yaw += factor.x;
	pitch += factor.y;
	if (yaw <= 0.0)
		yaw += 360.0;
	else if (yaw >= 360.0)
		yaw -= 360.0;
	yaw *= (M_PI / 180.0);
	pitch = ft_clampd(pitch, -89, 89) * (M_PI / 180.0);
	get_world_axis(&camera->front, FRONT);
	rotate_by_world_axis(RIGHT, pitch, &camera->front);
	rotate_by_world_axis(UP, -yaw, &camera->front);
	get_axes(&camera->front, &camera->right, &camera->up);
}
