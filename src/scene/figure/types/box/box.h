/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/27 00:00:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define BOX_ID "bo"
#include "scene/figure/types/quadrilater/quadrilater.h"

typedef struct s_face
{
	t_point				center;
	t_quadrilater_attrs	attrs;
}	t_face;

typedef struct s_box_attrs
{
	t_vector	orientation;
	float		width;
	float		height;
	float		length;
	t_face		faces[6];
}	t_box_attrs;

typedef struct s_figure	t_figure;

t_figure	*parse_box(t_parser_ctx *ctx, char **parts);
