/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:06:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_helper.h"
#include "libft.h"
#include "render/utils/random/random.h"
#include <math.h>

static void	set_viewport_coords(t_coordinates *vp_coords, t_render *render,
				t_iterators *iterators, uint64_t *seed)
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
				t_vector *defocus_up, uint64_t *seed)
{
	t_vector	offset;

	get_random_point_in_disk(seed, &offset);
	origin->x += (defocus_right->x * offset.x) - (defocus_up->x * offset.y);
	origin->y += (defocus_right->y * offset.x) - (defocus_up->y * offset.y);
	origin->z += (defocus_right->z * offset.x) - (defocus_up->z * offset.y);
}

void	set_ray_from_camera(t_ray *ray, t_render *render,
			t_iterators *iterators, uint64_t *seed)
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

void	set_shadow_ray(t_sample_lights_params *params, t_ray *shadow_ray,
	t_point *origin, t_point *light_pos)
{
	t_point		random_pos;
	t_point		final_light_pos;

	shadow_ray->origin = *origin;
	final_light_pos = *light_pos;
	if (params->render->soft_shadows_radius > 0.0)
	{
		get_random_point_in_sphere(params->seed, &random_pos);
		multiply_vector_scalar(&random_pos, params->render->soft_shadows_radius,
			&random_pos);
		sum_vectors(light_pos, &random_pos, &final_light_pos);
	}
	get_vector(&final_light_pos, &shadow_ray->origin, &shadow_ray->direction);
	shadow_ray->bounds.max = sqrt(dot(&shadow_ray->direction,
				&shadow_ray->direction));
	shadow_ray->bounds.min = 0.001;
	normalize(&shadow_ray->direction);
}
