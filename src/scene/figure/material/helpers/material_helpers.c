/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:21:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 20:34:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/utils/point/point.h"
#include "render/utils/random/random.h"
#include "render/strategies/shared/strategies_shared.h"
#include <math.h>

void	randomize_ray_direction(t_vector *ideal_bounce_direction,
	t_point *hit_point, uint32_t *seed, t_vector *res)
{
	t_point		ray_direction_point;
	t_vector	random_direction;
	t_vector	new_ray_point;

	get_random_point_in_sphere(seed, &random_direction);
	normalize(&random_direction);
	if (dot(&random_direction, ideal_bounce_direction) == -1.0)
	{
		*res = *ideal_bounce_direction;
		return ;
	}
	translate_point(hit_point, ideal_bounce_direction, 1, &ray_direction_point);
	translate_point(&random_direction, &ray_direction_point, 1, &new_ray_point);
	get_vector(&new_ray_point, hit_point, res);
}

int	diffuse_scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	t_vector	new_ray_direction;

	params->scatter_type = DIFFUSE;
	randomize_ray_direction(&params->hit_record.normal,
		&params->hit_record.point, seed, &new_ray_direction);
	set_ray(params->ray, &params->hit_record.point, &new_ray_direction);
	sample_lights(render, &params->hit_record, DIFFUSE, direct_light);
	return (1);
}

void	divert_ray_direction(t_vector *ray_dir, float roughness,
	uint32_t *seed, t_vector *res)
{
	t_vector	rnd_point;

	get_random_point_in_sphere(seed, &rnd_point);
	normalize(&rnd_point);
	multiply_vector_scalar(&rnd_point, pow(roughness, 2.0), &rnd_point);
	translate_point(&rnd_point, ray_dir, 1, res);
}

int	metallic_scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	t_metallic_attrs	*metallic_attrs;
	t_vector			new_ray_direction;
	t_vector			reflected;

	reflect(&params->ray->direction, &params->hit_record.normal, &reflected);
	new_ray_direction = reflected;
	metallic_attrs = params->attrs;
	params->scatter_type = METALLIC;
	if (metallic_attrs->roughness)
	{
		divert_ray_direction(&reflected, metallic_attrs->roughness, seed,
			&new_ray_direction);
		if (dot(&params->hit_record.normal, &new_ray_direction) < 0.0)
			return (0);
	}
	set_ray(params->ray, &params->hit_record.point, &new_ray_direction);
	sample_lights(render, &params->hit_record, METALLIC, direct_light);
	return (1);
}
