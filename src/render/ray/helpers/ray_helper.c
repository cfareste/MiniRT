/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 17:09:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "render/ray/ray.h"
#include "render/scene/camera/camera.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	set_ray_from_camera(t_ray *ray, t_camera *camera, int i, int j)
{
	t_coordinates	viewport_coords;
	t_point			origin;
	t_vector		direction;

	origin = camera->position;
	viewport_coords.x = camera->viewport.start.x
		+ (camera->right.x * camera->viewport.x_unit * i)
		- (camera->up.x * camera->viewport.y_unit * j);
	viewport_coords.y = camera->viewport.start.y
		+ (camera->right.y * camera->viewport.x_unit * i)
		- (camera->up.y * camera->viewport.y_unit * j);
	viewport_coords.z = camera->viewport.start.z
		+ (camera->right.z * camera->viewport.x_unit * i)
		- (camera->up.z * camera->viewport.y_unit * j);
	get_vector(&viewport_coords, &camera->position, &direction);
	set_ray(ray, &origin, &direction);
}

void	set_shadow_ray(t_ray *shadow_ray, t_point *origin, t_point *light_pos)
{
	shadow_ray->origin = *origin;
	get_vector(light_pos, &shadow_ray->origin, &shadow_ray->direction);
	shadow_ray->bounds.max = sqrt(dot(&shadow_ray->direction,
				&shadow_ray->direction));
	shadow_ray->bounds.min = 0.01;
	normalize(&shadow_ray->direction);
}
