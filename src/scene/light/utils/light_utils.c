/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 16:38:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/ray/ray.h"
#include "render/utils/vector/vector.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "libft.h"
#include "light_utils.h"
#include <math.h>

void	set_diffuse_params(t_ray *ray, t_hit_record *hit_record,
	t_diffuse_params *params)
{
	params->ray_direction = ray->direction;
	params->normal = hit_record->normal;
	params->hit_point = hit_record->point;
}

void	compute_diffuse(t_diffuse_params *params,
			t_light *light, t_color *color)
{
	float	strength;
	float	material_diffuse;
	t_color	aux;

	strength = dot(&params->ray_direction, &params->normal);
	if (strength < 0.0)
		strength = 0.0;
	strength *= 1 / pow(params->distance, 2.0);
	ft_bzero(&aux, sizeof(t_color));
	material_diffuse = 0.5;
	multiply_color_scalar(&light->color,
		strength * light->brightness * material_diffuse, &aux);
	sum_colors(color, &aux, color);
}

void	set_specular_params(t_scene *scene, t_ray *ray,
	t_hit_record *hit_record, t_specular_params *params)
{
	params->camera_vector = scene->camera->front;
	reflect(&ray->direction, &hit_record->normal, &params->ray_dir_reflected);
	params->material_glosiness = hit_record->figure->glosiness;
}

void	compute_specular(t_specular_params *params, t_light *light,
	t_color *color)
{
	float	strength;
	float	material_specular;
	t_color	aux;

	strength = dot(&params->camera_vector, &params->ray_dir_reflected);
	if (strength < 0.0)
		strength = 0.0;
	strength *= 1 / pow(params->distance, 2.0);
	material_specular = 0.5;
	strength = pow(strength, params->material_glosiness);
	multiply_color_scalar(&light->color,
		strength * light->brightness * material_specular, &aux);
	sum_colors(color, &aux, color);
}

void	apply_ambient_lighting(t_light *ambient, t_color *res)
{
	res->red += ambient->brightness * ambient->color.red;
	res->green += ambient->brightness * ambient->color.green;
	res->blue += ambient->brightness * ambient->color.blue;
}
