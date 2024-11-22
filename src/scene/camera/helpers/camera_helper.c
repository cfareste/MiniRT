/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:59 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/22 13:46:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera_helper.h"
#include "../parser/camera_parser.h"

void	update_camera_fov(t_camera *camera, int factor)
{
	int	new_fov;

	new_fov = camera->fov + factor;
	if (new_fov <= 180 && new_fov >= 0)
		camera->fov = new_fov;
}

void	update_camera_pos(t_camera *camera, t_point factor)
{
	camera->position.x += factor.x;
	camera->position.y += factor.y;
	camera->position.z += factor.z;
}

void	update_camera_focus_dis(t_camera *camera, double factor)
{
	camera->focus_dist += (factor * 0.2);
}

void	update_camera_front(t_camera *camera, t_point factor)
{
	camera->front.x += factor.x * 0.06;
	camera->front.y += factor.y * 0.06;
	camera->front.z += factor.z * 0.06;
	set_camera_vectors(camera);
}
