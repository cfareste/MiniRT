/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/06 17:43:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "utils/utils_bonus.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	set_viewport(t_camera *camera, t_viewport *vp, t_size w_size)
{
	float	viewport_fov;

	viewport_fov = tan((camera->fov * 0.5) * M_PI / 180);
	vp->width = 2.0 * viewport_fov * camera->focus_dist;
	vp->height = vp->width / (w_size.width / (float) w_size.height);
	vp->x_unit = vp->width / (float) w_size.width;
	vp->y_unit = vp->height / (float) w_size.height;
	translate_point(&camera->position, &camera->front, camera->focus_dist,
		&vp->center);
	vp->start.x = vp->center.x - (vp->width * camera->right.x / 2.0) + \
		(vp->height * camera->up.x / 2.0);
	vp->start.y = vp->center.y - (vp->width * camera->right.y / 2.0) + \
		(vp->height * camera->up.y / 2.0);
	vp->start.z = vp->center.z - (vp->width * camera->right.z / 2.0) + \
		(vp->height * camera->up.z / 2.0);
}

void	print_camera(t_camera *camera)
{
	printf("Camera (%p): \n \
		Position: %f, %f, %f \n \
		Front: %f, %f, %f \n \
		Right: %f, %f, %f \n \
		Up: %f, %f, %f \n \
		FOV: %i\n",
		camera,
		camera->position.x, camera->position.y, camera->position.z,
		camera->front.x, camera->front.y, camera->front.z,
		camera->right.x, camera->right.y, camera->right.z,
		camera->up.x, camera->up.y, camera->up.z,
		camera->fov);
}

void	update_camera_fov(t_camera *camera, int factor)
{
	int	new_fov;

	new_fov = camera->fov + factor;
	if (new_fov <= 180 && new_fov >= 0)
		camera->fov = new_fov;
}
