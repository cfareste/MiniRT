/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:54:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 16:24:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "scene/light/utils/light_utils.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/helpers/render_helper_bonus.h"
#include "render/utils/color/color_operations/color_operations.h"
#include <math.h>

static void	check_shadow_hits(t_figure **figure, t_ray *shadow_ray)
{
	float	distance;

	distance = FLT_MAX;
	while (*figure)
	{
		if ((*figure)->hit(*figure, shadow_ray, &distance))
			break ;
		*figure = (*figure)->next;
	}
}

static void	get_direct_lighting(t_diffuse_params *diff_params,
	t_specular_params *spec_params, t_light *light, t_color *color)
{
	t_vector	point_to_light;
	float		distance;

	get_vector(&light->position, &diff_params->hit_point, &point_to_light);
	distance = sqrt(dot(&point_to_light, &point_to_light));
	diff_params->distance = distance;
	spec_params->distance = distance;
	compute_diffuse(diff_params, light, color);
	compute_specular(spec_params, light, color);
}

void	sample_lights(t_scene *scene, t_hit_record *hit_record, t_color *color)
{
	t_ray				shadow_ray;
	t_light				*light;
	t_figure			*figure;
	t_diffuse_params	diff_params;
	t_specular_params	spec_params;

	light = scene->lights;
	while (light)
	{
		set_shadow_ray(&shadow_ray, &hit_record->point, &light->position);
		figure = scene->figures;
		check_shadow_hits(&figure, &shadow_ray);
		if (!figure)
		{
			set_diffuse_params(&shadow_ray, hit_record, &diff_params);
			set_specular_params(scene, &shadow_ray, hit_record, &spec_params);
			get_direct_lighting(&diff_params, &spec_params, light, color);
		}
		light = light->next;
	}
}

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record)
{
	t_figure	*figure;

	hit_record->distance = FLT_MAX;
	figure = scene->figures;
	while (figure)
	{
		if (figure->hit(figure, ray, &hit_record->distance))
			set_hit_record(hit_record, ray, figure);
		figure = figure->next;
	}
}
