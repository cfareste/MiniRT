/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:52:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define QUAD_ID "qu"
#include "render/utils/point/point_bonus.h"
#include "render/utils/color/color_bonus.h"

typedef struct s_quadrilater_attrs
{
	t_vector	orientation;
	float		width;
	float		height;
	t_vector	right;
	t_vector	up;
}	t_quadrilater_attrs;

typedef struct s_figure	t_figure;

void		set_quad(t_figure *quad, t_point *position,
				t_quadrilater_attrs *attrs);

t_figure	*new_quadrilater(t_point *pos, t_color *color,
				t_quadrilater_attrs *quad_attrs);
