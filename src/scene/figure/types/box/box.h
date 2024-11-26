/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:40:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 19:20:52 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define BOX_ID "bo"
#include "render/utils/vector/vector.h"

typedef struct s_box_attrs
{
	float				width;
	float				height;
	float				length;
	t_quadrilater_attrs	faces[6];
}	t_box_attrs;

typedef struct s_figure	t_figure;

t_figure	*parse_box(t_parser_ctx *ctx, char **parts);
