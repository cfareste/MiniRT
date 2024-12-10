/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:31 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:25:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define CYLINDER_H
#define CYLINDER_ID "cy"

#include "render/utils/color/color.h"
#include "scene/figure/figure.h"
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

t_figure	*new_cylinder(t_point *pos, t_color *color,
				t_cylinder_attrs *cy_attrs);
