/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/04 21:39:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define CAMERA_ID "C"

#include "utils/size/size.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "parser/parser.h"
#include "float.h"
#include <limits.h>

typedef struct s_viewport
{
	float	width;
	float	height;
	float	x_unit;
	float	y_unit;
	t_point	center;
	t_point	start;
}	t_viewport;

typedef struct s_camera_controls
{
	int		moving;
	int8_t	move_up;
	int8_t	move_right;
	int8_t	move_front;
	int8_t	view_up;
	int8_t	view_right;
	int8_t	zoom;
	int8_t	focus_dist;
}	t_camera_controls;

typedef struct s_camera
{
	t_point				position;
	t_vector			front;
	t_vector			right;
	t_vector			up;
	t_viewport			viewport;
	int					fov;
	double				defocus;
	double				focus_dist;
	t_vector			defocus_right;
	t_vector			defocus_up;
	t_camera_controls	controls;
}	t_camera;

void		print_camera(t_camera *camera);

void		set_viewport(t_camera *camera, t_viewport *vp, t_size w_size);

t_camera	*camera_dup(t_camera *camera, t_camera_controls *controls);

void		update_camera(t_camera *camera);
