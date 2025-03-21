/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_helpers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:13 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 20:37:28 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/reference_system/reference_system.h"

float	get_height(t_point *point, t_point *center, float base);

int		belongs_to_base(t_point *point, t_point *center, t_vector *normal,
			float height);

int		hit_base(t_reference_system *refsys, float base_center_distance,
			float radius, float *distance);

void	get_figure_color(t_figure *figure, t_point *point, t_color *res);

float	get_plane_center_to_hit(t_vector *normal, t_point *center, t_ray *ray,
			t_vector *center_to_hit);
