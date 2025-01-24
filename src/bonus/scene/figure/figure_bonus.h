/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/plane/plane_bonus.h"
#include "types/sphere/sphere_bonus.h"
#include "types/cylinder/cylinder_bonus.h"
#include "types/cone/cone_bonus.h"
#include "types/disk/disk_bonus.h"
#include "types/quadrilater/quadrilater_bonus.h"
#include "types/box/box_bonus.h"
#include "texture/bump_map/bump_map_bonus.h"
#include "pattern/pattern_bonus.h"
#include "material/material_bonus.h"
#include "scene/camera/camera_bonus.h"

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
	void		(*recalculate)(t_figure *figure);
	void		(*rotate)(t_figure *figure, t_camera *camera, t_point *factor);
	char		*(*compose)(t_figure *figure);
	void		(*free)(t_figure *figure);
	t_figure	*next;
}	t_figure;

void		free_figure(t_figure *figure);

void		free_figures(t_figure *figures);

t_figure	*new_figure(char *type, t_point *position, t_color *color);

int			control_figure(t_figure *figure, t_camera *camera,
				t_controls *controls);
