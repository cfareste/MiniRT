#ifndef CAMERA_H
# define CAMERA_H
# define CAMERA_ID 'C'

# include "shared/coordinates/coordinates.h"

typedef struct s_viewport
{
	float			width;
	float			height;
	float			x_unit;
	float			y_unit;
	t_coordinates	center;
	t_coordinates	start;
}	t_viewport;

typedef struct s_camera
{
	t_coordinates	position;
	t_coordinates	front;
	t_coordinates	right;
	t_coordinates	up;
	t_viewport		viewport;
	int				fov;
}	t_camera;

void	set_camera(char **parts, t_camera **camera);

void	print_camera(t_camera *camera);

#endif