#ifndef CAMERA_H
# define CAMERA_H
# define CAMERA_ID 'C'

# include "coordinates.h"

typedef struct s_camera
{
	char			id;
	t_coordinates	position;
	t_coordinates	orientation;
	int				fov;
}	t_camera;

void	set_camera(char **pieces, t_camera *camera);

#endif