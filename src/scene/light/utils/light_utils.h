/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/19 11:44:43 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "render/render_bonus.h"
#include "render/utils/color/color.h"

typedef struct s_specular_params
{
	t_vector	camera_vector;
	t_vector	ray_dir_reflected;
	float		material_glosiness;
}	t_specular_params;

void	compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record,
			t_light *light, t_color *color);

void	compute_specular(t_specular_params *params, t_light *light,
			t_color *color);

void	set_specular_params(t_scene *scene, t_ray *ray,
			t_hit_record *hit_record, t_specular_params *params);

void	apply_ambient_lighting(t_light *ambient, t_color *res);
