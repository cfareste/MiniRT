/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:33:49 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/scene.h"
#include "render/ray/ray.h"
#include "render/utils/color/color.h"
#include "render/utils/hit_record/hit_record.h"

typedef struct s_diffuse_params
{
	t_vector	ray_direction;
	t_vector	normal;
	float		distance;
}	t_diffuse_params;

typedef struct s_specular_params
{
	t_vector	camera_vector;
	t_vector	ray_dir_reflected;
	float		material_glossiness;
	float		distance;
}	t_specular_params;

typedef struct s_direct_lighting
{
	t_point				hit_point;
	t_diffuse_params	diffuse;
}	t_direct_lighting;

void	compute_diffuse(t_diffuse_params *params, float material_diffuse,
			t_light *light, t_color *color);

void	compute_specular(t_specular_params *params, float material_specular,
			t_light *light, t_color *color);

void	set_diffuse_params(t_ray *ray, t_hit_record *hit_record,
			t_diffuse_params *params);

void	apply_ambient_lighting(t_light *ambient, t_color *res);
