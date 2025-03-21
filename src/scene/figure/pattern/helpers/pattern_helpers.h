/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_helpers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/14 00:35:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"
#include "scene/figure/helpers/base_attributes/base_attributes.h"

typedef struct s_point_params
{
	float		point_base_height;
	float		point_pattern_dim;
	float		point_radius;
}	t_point_params;

void	get_base_pattern(t_figure *figure, t_point *point, t_base_attrs *attrs,
			t_color *res);
