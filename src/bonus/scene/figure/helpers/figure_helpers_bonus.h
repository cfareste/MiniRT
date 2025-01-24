/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_helpers_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:13 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/reference_system/reference_system_bonus.h"

float	get_height(t_point *point, t_point *center, float base);

int		belongs_to_base(t_point *point, t_point *center, t_vector *normal,
			float height);

int		hit_base(t_reference_system *refsys, float base_center_distance,
			float radius, float *distance);

void	get_figure_color(t_figure *figure, t_point *point, t_color *res);

float	get_plane_center_to_hit(t_vector *normal, t_point *center, t_ray *ray,
			t_vector *center_to_hit);
