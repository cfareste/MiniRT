/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_helpers_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure_bonus.h"
#include "scene/figure/helpers/base_attributes/base_attributes_bonus.h"

typedef struct s_point_params
{
	float		point_base_height;
	float		point_pattern_dim;
	float		point_radius;
}	t_point_params;

void	get_base_pattern(t_figure *figure, t_point *point, t_base_attrs *attrs,
			t_color *res);
