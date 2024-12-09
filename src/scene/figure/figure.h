/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/08 20:11:21 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/plane/plane.h"
#include "types/sphere/sphere.h"
#include "types/cylinder/cylinder.h"
#include "types/cone/cone.h"
#include "types/disk/disk.h"
#include "types/quadrilater/quadrilater.h"
#include "types/box/box.h"
#include "texture/bump_map/bump_map.h"
#include "pattern/pattern.h"
#include "material/material.h"

typedef struct s_figure
{
	char		*type;
	t_point		position;
	double		glossiness;
	t_material	material;
	union
	{
		void				*attrs;
		t_sphere_attrs		*sp_attrs;
		t_plane_attrs		*pl_attrs;
		t_cylinder_attrs	*cy_attrs;
		t_cone_attrs		*co_attrs;
		t_disk_attrs		*di_attrs;
		t_quadrilater_attrs	*qu_attrs;
		t_box_attrs			*bo_attrs;
	};
	t_color		color;
	t_pattern	pattern;
	t_bump_map	bump_map;
	int			(*hit)(t_figure *figure, t_ray *ray, float *distance);
	void		(*normal)(t_figure *figure, t_point *point, t_vector *res);
	void		(*get_color_pattern)(t_figure *figure, t_point *point,
			t_color *res);
	void		(*print_attrs)(void *attrs);
	void		(*rotate)(t_figure *figure, t_point *factor);
	void		(*free)(t_figure *figure);
	t_figure	*next;
}	t_figure;

void		free_figures(t_figure *figures);

void		print_figure(t_figure *figure);
