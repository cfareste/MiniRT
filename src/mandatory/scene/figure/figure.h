/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:50 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:23:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/plane/plane.h"
#include "types/sphere/sphere.h"
#include "types/cylinder/cylinder.h"
#include "scene/camera/camera.h"
#include "render/ray/ray.h"

typedef struct s_figure
{
	char		*type;
	t_point		position;
	union
	{
		void				*attrs;
		t_sphere_attrs		*sp_attrs;
		t_plane_attrs		*pl_attrs;
		t_cylinder_attrs	*cy_attrs;
	};
	t_color		color;
	int			(*hit)(t_figure *figure, t_ray *ray, float *distance);
	void		(*normal)(t_figure *figure, t_point *point, t_vector *res);
	void		(*print_attrs)(void *attrs);
	void		(*free)(t_figure *figure);
	t_figure	*next;
}	t_figure;

void		free_figure(t_figure *figure);

void		free_figures(t_figure *figures);

t_figure	*new_figure(char *type, t_point *position, t_color *color);
