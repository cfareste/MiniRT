/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 16:08:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ray_helper.h"
#include "utils/utils_bonus.h"
#include "render/ray/ray.h"
#include "scene/scene.h"
#include "scene/camera/camera.h"
#include "render/utils/vector/vector.h"
#include "render/utils/random/random.h"
#include "utils/iterators/iterators.h"
#include <math.h>

static void	set_viewport_coords(t_coordinates *vp_coords, t_render *render,
				t_iterators *iterators, uint32_t *seed)
{
	t_vector	offset;
	t_camera	*camera;

	camera = render->scene.camera;
	ft_bzero(&offset, sizeof(t_vector));
	if (render->antialiasing)
		get_random_point_in_square(seed, &offset);
	vp_coords->x = camera->viewport.start.x
		+ (camera->right.x * camera->viewport.x_unit
			* (iterators->i + offset.x))
		- (camera->up.x * camera->viewport.y_unit * (iterators->j + offset.y));
	vp_coords->y = camera->viewport.start.y
		+ (camera->right.y * camera->viewport.x_unit
			* (iterators->i + offset.x))
		- (camera->up.y * camera->viewport.y_unit * (iterators->j + offset.y));
	vp_coords->z = camera->viewport.start.z
		+ (camera->right.z * camera->viewport.x_unit
			* (iterators->i + offset.x))
		- (camera->up.z * camera->viewport.y_unit * (iterators->j + offset.y));
}

static void	randomize_ray_origin(t_point *origin, t_vector *defocus_right,
				t_vector *defocus_up, uint32_t *seed)
{
	t_vector	offset;

	get_random_point_in_disk(seed, &offset);
	origin->x += (defocus_right->x * offset.x) - (defocus_up->x * offset.y);
	origin->y += (defocus_right->y * offset.x) - (defocus_up->y * offset.y);
	origin->z += (defocus_right->z * offset.x) - (defocus_up->z * offset.y);
}

void	set_ray_from_camera(t_ray *ray, t_render *render,
			t_iterators *iterators, uint32_t *seed)
{
	t_coordinates	vp_coords;
	t_camera		*camera;
	t_vector		direction;
	t_point			origin;

	camera = render->scene.camera;
	origin = render->scene.camera->position;
	set_viewport_coords(&vp_coords, render, iterators, seed);
	if (render->scene.camera->defocus > 0)
		randomize_ray_origin(&origin, &camera->defocus_right,
			&camera->defocus_up, seed);
	get_vector(&vp_coords, &origin, &direction);
	set_ray(ray, &origin, &direction);
}

void	set_shadow_ray(t_ray *shadow_ray, t_point *origin, t_point *light_pos)
{
	shadow_ray->origin = *origin;
	get_vector(light_pos, &shadow_ray->origin, &shadow_ray->direction);
	shadow_ray->bounds.max = sqrt(dot(&shadow_ray->direction,
				&shadow_ray->direction));
	shadow_ray->bounds.min = 0.001;
	normalize(&shadow_ray->direction);
}
