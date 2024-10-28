/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 17:36:09 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "utils/utils.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	set_viewport(t_camera *camera, t_viewport *vp, t_size w_size)
{
	float	focal_distance;

	vp->height = 2.0;
	vp->width = (w_size.width * vp->height) / w_size.height;
	vp->x_unit = vp->width / w_size.width;
	vp->y_unit = vp->height / w_size.height;
	focal_distance = tan((camera->fov * 0.5) * M_PI / 180);
	translate_point(&camera->position, &camera->front, focal_distance,
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
