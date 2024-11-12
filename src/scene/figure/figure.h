/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/12 01:56:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"
#include "types/plane/plane.h"
#include "types/sphere/sphere.h"
#include "types/cylinder/cylinder.h"
#include "types/cone/cone.h"
#include "render/utils/color/color.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"
#include "texture/bump_map/bump_map.h"
#include "pattern/pattern.h"

typedef struct s_figure
{
	char		*type;
	t_point		position;
	double		glosiness;
	double		diffuse;
	double		specular;
	union
	{
		void				*attrs;
		t_sphere_attrs		*sp_attrs;
		t_plane_attrs		*pl_attrs;
		t_cylinder_attrs	*cy_attrs;
		t_cone_attrs		*co_attrs;
	};
	t_color		color;
	t_pattern	pattern;
	t_bump_map	bump_map;
	int			(*hit)(t_figure *figure, t_ray *ray, float *distance);
	void		(*normal)(t_figure *figure, t_point *point, t_vector *res);
	void		(*get_color_pattern)(t_figure *figure, t_point *point,
			t_color *res);
	void		(*print_attrs)(void *attrs);
	void		(*free)(t_figure *figure);
	t_figure	*next;
}	t_figure;

void		free_figures(t_figure *figures);

void		print_figure(t_figure *figure);
