/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes_shared.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:54:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 18:32:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "scene/light/utils/light_utils.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/helpers/render_helper_bonus.h"
#include "render/utils/color/color_operations/color_operations.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure)
{
	if (hit_record->distance >= ray->bounds.max)
		return ;
	ray->bounds.max = hit_record->distance;
	hit_record->figure = figure;
	translate_point(&ray->origin, &ray->direction, hit_record->distance,
		&hit_record->point);
	figure->normal(figure, &hit_record->point, &hit_record->normal);
}

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

void	check_lights(t_hit_record *hit_record, t_scene *scene, t_color *color)
{
	t_ray		shadow_ray;
	t_light		*light;
	t_figure	*figure;

	light = scene->lights;
	while (light)
	{
		set_shadow_ray(&shadow_ray, &hit_record->point, &light->position);
		figure = scene->figures;
		check_shadow_hits(&figure, &shadow_ray);
		if (!figure)
		{
			compute_diffuse(&shadow_ray, hit_record, light, color);
			sum_colors(color, compute_specular(scene, get_reflection(
						&shadow_ray, hit_record), light, hit_record), color);
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
