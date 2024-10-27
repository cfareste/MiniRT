/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:55:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "render/ray/ray.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record,
			t_light *light, t_color *color)
{
	float	strength;

	strength = dot(&shadow_ray->direction, &hit_record->normal);
	if (strength < 0.0)
		strength = 0.0;
	color->red += strength * light->brightness * light->color.red * 0.5;
	color->green += strength * light->brightness * light->color.green * 0.5;
	color->blue += strength * light->brightness * light->color.blue * 0.5;
}

t_vector	get_reflection(t_ray *shadow_ray, t_hit_record *hit_record)
{
	t_vector	reflected;

	reflect(&shadow_ray->direction, &hit_record->normal, &reflected);
	return (reflected);
}

void	compute_specular(t_scene *scene, t_vector reflected,
			t_light *light, t_color *color)
{
	float			strength;

	strength = dot(&scene->camera->front, &reflected);
	if (strength < 0.0)
		strength = 0.0;
	strength = pow(strength, 256.0);
	color->red += strength * light->brightness * light->color.red * 0.5;
	color->green += strength * light->brightness * light->color.green * 0.5;
	color->blue += strength * light->brightness * light->color.blue * 0.5;
}

void	apply_ambient_lighting(t_light *ambient, t_color *res)
{
	res->red += ambient->brightness * ambient->color.red;
	res->green += ambient->brightness * ambient->color.green;
	res->blue += ambient->brightness * ambient->color.blue;
}
