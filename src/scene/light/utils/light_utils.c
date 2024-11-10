/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/03 14:29:24 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/ray/ray.h"
#include "render/utils/vector/vector.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "libft.h"
#include <math.h>

void	compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record,
			t_light *light, t_color *color)
{
	float	strength;
	float	material_diffuse;
	t_color	aux;

	strength = dot(&shadow_ray->direction, &hit_record->normal);
	if (strength < 0.0)
		strength = 0.0;
	ft_bzero(&aux, sizeof(t_color));
	material_diffuse = hit_record->figure->diffuse;
	multiply_color_scalar(&light->color,
		strength * light->brightness * material_diffuse, &aux);
	sum_colors(color, aux, color);
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
	float	material_specular;
	t_color	color;

	strength = dot(&scene->camera->front, &reflected);
	if (strength < 0.0)
		strength = 0.0;
	material_specular = hit_record->figure->specular;
	strength = pow(strength, hit_record->figure->glosiness);
	multiply_color_scalar(&light->color,
		strength * light->brightness * material_specular, &color);
	return (color);
}

void	apply_ambient_lighting(t_light *ambient, t_color *res)
{
	res->red += ambient->brightness * ambient->color.red;
	res->green += ambient->brightness * ambient->color.green;
	res->blue += ambient->brightness * ambient->color.blue;
}
