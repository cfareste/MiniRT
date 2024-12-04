/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:59 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/04 19:42:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera_helper.h"
#include "../parser/camera_parser.h"

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
		translate_point(&camera->position, &camera->up, factor.y,
			&camera->position);
	if (factor.z)
		translate_point(&camera->position, &camera->front, factor.z,
			&camera->position);
}

void	update_camera_focus_dis(t_camera *camera, double factor)
{
	if (!factor)
		return ;
	camera->focus_dist += (factor * 0.2);
}

void	update_camera_front(t_camera *camera, t_point factor)
{
	if (!factor.x && !factor.y && !factor.z)
		return ;
	camera->front.x += factor.x;
	camera->front.y += factor.y;
	camera->front.z += factor.z;
	get_axes(&camera->front, &camera->right, &camera->up);
}
