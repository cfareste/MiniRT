/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/06 17:27:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define CAMERA_ID "C"
#include "utils/size/size.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "parser/parser.h"

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
