/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_helpers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/11 00:52:02 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"

typedef struct s_point_params
{
	float		point_base_height;
	float		point_pattern_dim;
	float		point_radius;
}	t_point_params;

void	get_base_pattern(t_figure *figure, t_point *point, float radius,
			t_color *res);
