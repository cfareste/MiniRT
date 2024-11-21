/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:35:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 13:24:02 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/utils/point/point.h"
#include "render/utils/random/random.h"
#include "scene/figure/material/material.h"
#include "scene/light/light.h"
#include "render/strategies/shared/strategies_shared.h"
#include "scene/figure/material/helpers/material_helpers.h"
#include "float.h"

static void	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	t_vector	new_ray_direction;

	randomize_ray_direction(&params->hit_record.normal,
		&params->hit_record.point, seed, &new_ray_direction);
	set_ray(params->ray, &params->hit_record.point, &new_ray_direction);
	sample_lights(render, &params->hit_record, DIFFUSE, direct_light);
}

void	parse_diffuse(t_material *material)
{
	material->type = DIFFUSE;
	material->material_attrs = NULL;
	material->scatter = scatter;
}
