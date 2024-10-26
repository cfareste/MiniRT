#pragma once

#define CAMERA_ID 'C'

#include "utils/size/size.h"
#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

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
}	t_camera;

void	set_camera(char **parts, t_camera **camera);

void	print_camera(t_camera *camera);

void	set_viewport(t_camera *camera, t_viewport *vp, t_size w_size);
