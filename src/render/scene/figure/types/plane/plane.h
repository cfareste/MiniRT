/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 09:10:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define PLANE_ID "pl"

#include "render/utils/coordinates/coordinates.h"
#include "parser/parser.h"

typedef struct s_plane_attrs
{
	t_vector	orientation;
}	t_plane_attrs;

typedef struct s_figure	t_figure;

void		set_plane(t_figure *plane, t_point *position, t_plane_attrs *attrs);
