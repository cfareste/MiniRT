#ifndef SCENE_H
# define SCENE_H

# include "utils.h"
# include "light.h"
# include "figure.h"

typedef struct s_camera
{
	char			id;
	t_coordinates	position;
	t_coordinates	orientation;
	int				fov;
}	t_camera;

typedef struct s_scene
{
	t_light		ambient_light;
	t_camera	camera;
	t_light		*lights;
	t_figure	*figures;
}	t_scene;

#endif