/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_helpers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 17:26:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/scene/figure/figure.h"

typedef struct s_point_params
{
	float		point_base_height;
	float		point_pattern_dim;
	float		point_radius;
}	t_point_params;

void	get_cylinder_body_pattern(t_figure *figure, t_point *point,
			t_color *res);

void	get_plane_pattern(t_figure *figure, t_point *point, t_color *res);

void	get_cone_body_pattern(t_figure *figure, t_point *point, t_color *res);

void	get_base_pattern(t_figure *figure, t_point *point, float radius,
			t_color *res);
