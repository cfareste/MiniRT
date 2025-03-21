/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "libft.h"
#include "utils/utils.h"
#include "helpers/camera_helper.h"
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

t_camera	*camera_dup(t_camera *camera)
{
	t_camera	*new;

	new = ft_calloc(1, sizeof(t_camera));
	if (!new)
		throw_sys_error("trying to allocate t_camera");
	*new = *camera;
	return (new);
}

void	calculate_defocus_components(t_camera *camera)
{
	float	defocus_radius;

	defocus_radius = tan(camera->defocus * 0.5 * M_PI / 180.0)
		* camera->focus_dist;
	multiply_vector_scalar(&camera->right, defocus_radius,
		&camera->defocus_right);
	multiply_vector_scalar(&camera->up, defocus_radius,
		&camera->defocus_up);
}

int	control_camera(t_camera *camera, t_controls *controls)
{
	if (!controls->moving)
		return (0);
	update_camera_focus_dis(camera, controls->focus_dist);
	update_camera_defocus_rad(camera, controls->defocus);
	update_camera_fov(camera, controls->zoom);
	update_camera_front(camera, wrap_point(
			2 * controls->view_right,
			2 * controls->view_up, 0));
	update_camera_pos(camera, wrap_point(
			0.2 * controls->move_right,
			0.2 * controls->move_up,
			0.2 * controls->move_front));
	return (1);
}
