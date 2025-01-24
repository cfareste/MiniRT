/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_helpers_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:47:43 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure_bonus.h"
#include "scene/figure/helpers/base_attributes/base_attributes_bonus.h"

typedef struct s_base_point_context
{
	float	point_radius;
	float	point_arc;
	float	point_base_height;
}	t_base_point_context;

void	get_pixel_normal(uint8_t *pixel, t_bump_map_format format,
			t_vector *res);

void	rotate_bump_to_point_position(t_vector *point_normal, t_vector *res);

void	get_base_bump_normal(t_figure *figure, t_point *point,
			t_base_attrs *base_attrs, t_vector *res);
