/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 02:12:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "utils/utils_bonus.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "parser/camera_parser.h"
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

void	update_camera_pos(t_camera *camera, t_point factor)
{
	printf("0 -> Camera position: %f,%f,%f\n",
		camera->position.x,
		camera->position.y,
		camera->position.z);
	camera->position.x += factor.x;
	camera->position.y += factor.y;
	camera->position.z += factor.z;
	printf("1 -> Camera position: %f,%f,%f\n",
		camera->position.x,
		camera->position.y,
		camera->position.z);
}

void	update_camera_focus_dis(t_camera *camera, double factor)
{
	camera->focus_dist += (factor * 0.2);
}

void	update_camera_front(t_camera *camera, t_point factor)
{
	printf("0 -> Camera front: %f,%f,%f\n",
		camera->front.x,
		camera->front.y,
		camera->front.z);
	camera->front.x += factor.x * 0.06;
	camera->front.y += factor.y * 0.06;
	camera->front.z += factor.z * 0.06;
	set_camera_vectors(camera);
	printf("2 -> Camera front: %f,%f,%f\n",
		camera->front.x,
		camera->front.y,
		camera->front.z);
}
