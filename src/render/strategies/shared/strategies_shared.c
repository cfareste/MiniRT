/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:54:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:17:52 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strategies_shared.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/strategies/raytracing/helpers/raytracing_helpers.h"
#include "render/strategies/pathtracing/helpers/pathtracing_helpers.h"
#include "libft.h"
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
	if (render->curr_strategy == PATHTRACING)
		pt_compute_direct_light_comps(direct_lighting, light, color);
	else if (render->curr_strategy == RAYTRACING)
		rt_compute_direct_light_comps(direct_lighting, light, color);
}

void	sample_lights(t_sample_lights_params *params, t_hit_record *hit_record,
	t_material_type scatter_type, t_color *color)
{
	t_ray				shadow_ray;
	t_light				*light;
	t_figure			*figure;
	t_direct_lighting	direct_lighting;

	light = params->render->scene.lights;
	while (light)
	{
		set_shadow_ray(params, &shadow_ray, &hit_record->point,
			&light->position);
		figure = params->render->scene.figures;
		check_shadow_hits(&figure, &shadow_ray);
		if (!figure)
		{
			direct_lighting.hit_point = hit_record->point;
			direct_lighting.scatter_type = scatter_type;
			set_diffuse_params(&shadow_ray, hit_record,
				&direct_lighting.diffuse);
			set_specular_params(&params->render->scene, &shadow_ray, hit_record,
				&direct_lighting.specular);
			compute_direct_lighting(params->render, &direct_lighting, light,
				color);
		}
		light = light->next;
	}
}

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record)
{
	t_figure	*figure;
	t_vector	hit_vector;

	ft_bzero(hit_record, sizeof(t_hit_record));
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
	if (scene->settings.sky_box)
	{
		get_vector(&hit_record->point, &scene->camera->position, &hit_vector);
		if (sqrt(dot(&hit_vector, &hit_vector))
			>= scene->settings.sky_box->sp_attrs->radius)
			return (ft_bzero(hit_record, sizeof(t_hit_record)));
	}
	hit_record->figure->normal(hit_record->figure, &hit_record->point,
		&hit_record->normal);
}
