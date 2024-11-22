/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 02:08:41 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define CAMERA_ID "C"
#include "utils/size/size.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "parser/parser.h"
#include <limits.h>
#include <float.h>
#define CAMERA_MAX_X DBL_MAX
#define CAMERA_MAX_Y DBL_MAX
#define CAMERA_MAX_Z DBL_MAX

typedef struct s_viewport
{
	float	width;
	float	height;
	float	x_unit;
	float	y_unit;
	t_point	center;
	t_point	start;
}	t_viewport;

typedef struct s_camera
{
	t_point		position;
	t_vector	front;
	t_vector	right;
	t_vector	up;
	t_viewport	viewport;
	int			fov;
	double		defocus;
	double		focus_dist;
	t_vector	defocus_right;
	t_vector	defocus_up;
}	t_camera;

void	print_camera(t_camera *camera);

void	set_viewport(t_camera *camera, t_viewport *vp, t_size w_size);

void	update_camera_fov(t_camera *camera, int factor);

void	update_camera_pos(t_camera *camera, t_point factor);

void	update_camera_front(t_camera *camera, t_point factor);

void	update_camera_focus_dis(t_camera *camera, double factor);
