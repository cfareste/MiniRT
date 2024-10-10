#ifndef SCENE_H
# define SCENE_H

# include "utils.h"
# include "light.h"
# include "figure.h"
# include "camera.h"

typedef struct s_scene
{
	t_light		ambient_light;
	t_camera	camera;
	t_light		*lights;
	t_figure	*figures;
}	t_scene;

void	create_scene(t_scene *scene, char *filename);

#endif