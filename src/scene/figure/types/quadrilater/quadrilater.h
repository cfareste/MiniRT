/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:52:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 23:36:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define QUAD_ID "qu"
#include "render/utils/point/point.h"

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

t_figure	*parse_quadrilater(t_parser_ctx *ctx, char **parts);
