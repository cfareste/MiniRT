/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:35:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 20:15:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/utils/point/point.h"
#include "render/utils/random/random.h"
#include "scene/figure/material/material.h"
#include "scene/light/light.h"
#include "render/strategies/shared/strategies_shared.h"
#include "float.h"

static void	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	t_point		rnd_point;
	t_point		normal_point;
	t_point		new_ray_point;
	t_vector	new_ray_direction;

	get_random_point_in_sphere(seed, &rnd_point);
	normalize(&rnd_point);
	if (dot(&rnd_point, &params->hit_record.normal) == -1.0)
		return (set_ray(params->ray, &params->hit_record.point,
				&params->hit_record.normal));
	translate_point(&params->hit_record.point, &params->hit_record.normal, 1,
		&normal_point);
	translate_point(&rnd_point, &normal_point, 1, &new_ray_point);
	get_vector(&new_ray_point, &params->hit_record.point, &new_ray_direction);
	set_ray(params->ray, &params->hit_record.point, &new_ray_direction);
	sample_lights(render, &params->hit_record, DIFFUSE, direct_light);
}

void	parse_diffuse(t_material *material)
{
	material->type = DIFFUSE;
	material->material_attrs = NULL;
	material->scatter = scatter;
}
