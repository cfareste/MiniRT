/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:38:14 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_helper.h"
#include "libft.h"
#include <math.h>

static void	set_viewport_coords(t_coordinates *vp_coords, t_render *render,
				t_iterators *iterators)
{
	t_camera	*camera;

	camera = render->scene.camera;
	vp_coords->x = camera->viewport.start.x
		+ (camera->right.x * camera->viewport.x_unit
			* (iterators->i))
		- (camera->up.x * camera->viewport.y_unit * (iterators->j));
	vp_coords->y = camera->viewport.start.y
		+ (camera->right.y * camera->viewport.x_unit
			* (iterators->i))
		- (camera->up.y * camera->viewport.y_unit * (iterators->j));
	vp_coords->z = camera->viewport.start.z
		+ (camera->right.z * camera->viewport.x_unit
			* (iterators->i))
		- (camera->up.z * camera->viewport.y_unit * (iterators->j));
}

void	set_ray_from_camera(t_ray *ray, t_render *render,
			t_iterators *iterators)
{
	t_coordinates	vp_coords;
	t_camera		*camera;
	t_vector		direction;
	t_point			origin;

	camera = render->scene.camera;
	origin = render->scene.camera->position;
	set_viewport_coords(&vp_coords, render, iterators);
	printf("Vp coord: %f, %f, %f\n",
		vp_coords.x, vp_coords.y, vp_coords.z);
	get_vector(&vp_coords, &origin, &direction);
	set_ray(ray, &origin, &direction);
}

void	set_shadow_ray(t_ray *shadow_ray, t_point *origin, t_point *light_pos)
{
	t_point		final_light_pos;

	shadow_ray->origin = *origin;
	final_light_pos = *light_pos;
	get_vector(&final_light_pos, &shadow_ray->origin, &shadow_ray->direction);
	shadow_ray->bounds.max = sqrt(dot(&shadow_ray->direction,
				&shadow_ray->direction));
	shadow_ray->bounds.min = 0.001;
	normalize(&shadow_ray->direction);
}
