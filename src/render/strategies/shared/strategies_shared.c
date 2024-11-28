/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:54:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/28 16:50:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "scene/light/utils/light_utils.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/helpers/render_helper_bonus.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "render/strategies/raytracing/helpers/raytracing_helpers.h"
#include "render/strategies/pathtracing/helpers/pathtracing_helpers.h"
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

static void	compute_direct_lighting(t_render *render,
	t_direct_lighting *direct_lighting, t_light *light, t_color *color)
{
	t_vector	point_to_light;
	float		distance;

	get_vector(&light->position, &direct_lighting->hit_point,
		&point_to_light);
	distance = sqrt(dot(&point_to_light, &point_to_light));
	direct_lighting->diffuse.distance = distance;
	direct_lighting->specular.distance = distance;
	if (!render->raytracing)
		pt_compute_direct_light_comps(direct_lighting, light, color);
	else
		rt_compute_direct_light_comps(direct_lighting, light, color);
}

void	sample_lights(t_render *render, t_hit_record *hit_record,
	t_material_type scatter_type, t_color *color)
{
	t_ray				shadow_ray;
	t_light				*light;
	t_figure			*figure;
	t_direct_lighting	direct_lighting;

	light = render->scene.lights;
	while (light)
	{
		set_shadow_ray(&shadow_ray, &hit_record->point, &light->position);
		figure = render->scene.figures;
		check_shadow_hits(&figure, &shadow_ray);
		if (!figure)
		{
			direct_lighting.hit_point = hit_record->point;
			direct_lighting.scatter_type = scatter_type;
			set_diffuse_params(&shadow_ray, hit_record,
				&direct_lighting.diffuse);
			set_specular_params(&render->scene, &shadow_ray, hit_record,
				&direct_lighting.specular);
			compute_direct_lighting(render, &direct_lighting, light,
				color);
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
	if (!hit_record->figure)
		return ;
	translate_point(&ray->origin, &ray->direction, hit_record->distance,
		&hit_record->point);
	hit_record->figure->normal(hit_record->figure, &hit_record->point,
		&hit_record->normal);
}
