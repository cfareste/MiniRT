/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/31 14:06:26 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "render/render_bonus.h"
#include "render/utils/color/color.h"

void		compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record,
				t_light *light, t_color *color);

t_color		compute_specular(t_scene *scene, t_vector reflected,
				t_light *light, t_hit_record *hit_record);

t_vector	get_reflection(t_ray *shadow_ray, t_hit_record *hit_record);

void		apply_ambient_lighting(t_light *ambient, t_color *res);

void		sum_colors(t_color *light_color, t_color color, t_color *res);
