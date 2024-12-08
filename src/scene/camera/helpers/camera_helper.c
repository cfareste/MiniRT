/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:59 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/08 16:20:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera_helper.h"
#include "../parser/camera_parser.h"
#include "render/utils/reference_system/reference_system.h"
#include <math.h>

void	update_camera_fov(t_camera *camera, int factor)
{
	int	new_fov;

	if (!factor)
		return ;
	new_fov = camera->fov + factor;
	if (new_fov <= 180 && new_fov >= 0)
		camera->fov = new_fov;
}

void	update_camera_pos(t_camera *camera, t_point factor)
{
	if (factor.x)
		translate_point(&camera->position, &camera->right, factor.x,
			&camera->position);
	if (factor.y)
		camera->position.y += factor.y;
	if (factor.z)
	{
		camera->position.x += camera->front.x * factor.z;
		camera->position.z += camera->front.z * factor.z;
	}
}

void	update_camera_focus_dis(t_camera *camera, double factor)
{
	if (!factor)
		return ;
	camera->focus_dist += (factor * 0.2);
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
	pitch = ft_fclamp(pitch, -90, 90) * (M_PI / 180.0);
	get_world_axis(&camera->front, FRONT);
	rotate_by_axis(RIGHT, pitch, &camera->front);
	rotate_by_axis(UP, -yaw, &camera->front);
	get_axes(&camera->front, &camera->right, &camera->up);
}
