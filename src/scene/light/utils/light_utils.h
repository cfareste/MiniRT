/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "render/render_bonus.h"
#include "render/utils/color/color.h"

typedef struct s_diffuse_params
{
	t_vector	ray_direction;
	t_vector	normal;
	t_point		hit_point;
	float		distance;
}	t_diffuse_params;

typedef struct s_specular_params
{
	t_vector	camera_vector;
	t_vector	ray_dir_reflected;
	float		material_glosiness;
	float		distance;
}	t_specular_params;

void	compute_diffuse(t_diffuse_params *params, t_light *light,
			t_color *color);

void	compute_specular(t_specular_params *params, t_light *light,
			t_color *color);

void	set_diffuse_params(t_ray *ray, t_hit_record *hit_record,
			t_diffuse_params *params);

void	set_specular_params(t_scene *scene, t_ray *ray,
			t_hit_record *hit_record, t_specular_params *params);

void	apply_ambient_lighting(t_light *ambient, t_color *res);
