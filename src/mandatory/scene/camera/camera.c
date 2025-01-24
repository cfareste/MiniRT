/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:03 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:30:32 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "libft.h"
#include "utils/utils.h"
#include <math.h>

void	set_viewport(t_camera *camera, t_viewport *vp, t_size w_size)
{
	float	viewport_fov;

	viewport_fov = tan((camera->fov * 0.5) * M_PI / 180);
	vp->width = 2.0 * viewport_fov;
	vp->height = vp->width / (w_size.width / (float) w_size.height);
	vp->x_unit = vp->width / (float) w_size.width;
	vp->y_unit = vp->height / (float) w_size.height;
	// translate_point(&camera->position, &camera->front, 4,
	// 	&vp->center);
	vp->start.x = vp->center.x - (vp->width * camera->right.x / 2.0) + \
		(vp->height * camera->up.x / 2.0);
	vp->start.y = vp->center.y - (vp->width * camera->right.y / 2.0) + \
		(vp->height * camera->up.y / 2.0);
	vp->start.z = vp->center.z - (vp->width * camera->right.z / 2.0) + \
		(vp->height * camera->up.z / 2.0);
}
