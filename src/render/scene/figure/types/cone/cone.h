/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:16 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/28 18:21:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define CONE_ID "co"

#include "render/utils/coordinates/coordinates.h"
#include "render/scene/figure/figure.h"

typedef struct s_cone_attrs
{
	double			radius;
	double			height;
	t_coordinates	orientation;
}	t_cone_attrs;

t_figure	*parse_cone(t_parser_ctx *ctx, char **parts);

void		set_cone(t_figure *cone, double radius, double height,
				t_cone_attrs *attrs);
