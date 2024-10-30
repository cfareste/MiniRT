/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:31 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 18:14:27 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define CYLINDER_H
#define CYLINDER_ID "cy"

#include "render/utils/color/color.h"
#include "render/scene/figure/figure.h"
#include "render/utils/point/point.h"
#include "render/ray/ray.h"
#include "parser/parser.h"

typedef struct s_cylinder_attrs
{
	double		radius;
	double		height;
	t_vector	orientation;
}	t_cylinder_attrs;

typedef struct s_figure	t_figure;

t_figure	*parse_cylinder(t_parser_ctx *ctx, char **parts);
