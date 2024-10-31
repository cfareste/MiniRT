/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:06 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/ray/ray.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record,
			t_light *light, t_color *color)
{
	float	strength;
	float	mat_dff;

	strength = dot(&shadow_ray->direction, &hit_record->normal);
	if (strength < 0.0)
		strength = 0.0;
	mat_dff = hit_record->figure->diffuse;
	color->red += strength * light->brightness * light->color.red * mat_dff;
	color->green += strength * light->brightness * light->color.green * mat_dff;
	color->blue += strength * light->brightness * light->color.blue * mat_dff;
}

t_vector	get_reflection(t_ray *shadow_ray, t_hit_record *hit_record)
{
	t_vector	reflected;

	reflect(&shadow_ray->direction, &hit_record->normal, &reflected);
	return (reflected);
}

t_color	compute_specular(t_scene *scene, t_vector reflected,
			t_light *light, t_hit_record *hit_record)
{
	float	strength;
	float	mat_spec;
	t_color	color;

	strength = dot(&scene->camera->front, &reflected);
	if (strength < 0.0)
		strength = 0.0;
	mat_spec = hit_record->figure->specular;
	strength = pow(strength, hit_record->figure->glosiness);
	color.red = strength * light->brightness * light->color.red * mat_spec;
	color.green = strength * light->brightness * light->color.green * mat_spec;
	color.blue = strength * light->brightness * light->color.blue * mat_spec;
	return (color);
}

void	apply_ambient_lighting(t_light *ambient, t_color *res)
{
	res->red += ambient->brightness * ambient->color.red;
	res->green += ambient->brightness * ambient->color.green;
	res->blue += ambient->brightness * ambient->color.blue;
}

void	sum_colors(t_color *light_color, t_color color, t_color *res)
{
	res->red = light_color->red + color.red;
	res->green = light_color->green + color.green;
	res->blue = light_color->blue + color.blue;
}
