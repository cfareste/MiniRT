/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 20:08:59 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define CAMERA_ID "C"

#include "utils/size/size.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "window/controls/window_controls.h"
#include <float.h>
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
}	t_camera;

void		set_viewport(t_camera *camera, t_viewport *vp, t_size w_size);

t_camera	*camera_dup(t_camera *camera);

void		calculate_defocus_components(t_camera *camera);

int			control_camera(t_camera *camera, t_controls *controls);
