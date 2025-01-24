/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 01:03:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define PLANE_ID "pl"

#include "render/utils/point/point.h"
#include "render/utils/color/color.h"

typedef struct s_plane_attrs
{
	t_vector	orientation;
}	t_plane_attrs;

typedef struct s_figure	t_figure;

void		set_plane(t_figure *plane, t_point *position, t_plane_attrs *attrs);

t_figure	*new_plane(t_point *pos, t_color *color, t_plane_attrs *pl_attrs);
