/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:54:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "utils/utils.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	set_camera(char **parts, t_camera **camera)
{
	t_vector	world_axis;

	if (*camera)
		throw_error("Multiple cameras are not allowed");
	else if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing camera params");
	*camera = ft_calloc(1, sizeof(t_camera));
	if (!*camera)
		throw_sys_error("trying to allocate t_camera");
	set_coordinates(parts[1], &(*camera)->position);
	set_coordinates(parts[2], &(*camera)->front);
	(*camera)->fov = ft_atoi(parts[3]);
	normalize(&(*camera)->front);
	get_axis(&world_axis, UP);
	if (dot(&(*camera)->front, &world_axis) == 1.0)
		get_axis(&world_axis, BACK);
	else if (dot(&(*camera)->front, &world_axis) == -1.0)
		get_axis(&world_axis, FRONT);
	cross(&(*camera)->front, &world_axis, &(*camera)->right);
	normalize(&(*camera)->right);
	cross(&(*camera)->right, &(*camera)->front, &(*camera)->up);
	normalize(&(*camera)->up);
}

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