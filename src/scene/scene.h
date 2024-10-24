#ifndef SCENE_H
# define SCENE_H
# define SCENE_FILE_EXTENSION ".rt"

# include "utils/utils.h"
# include "light/light.h"
# include "figure/figure.h"
# include "camera/camera.h"

typedef struct s_scene
{
	t_light		*ambient_light;
	t_camera	*camera;
	t_light		*lights;
	t_figure	*figures;
	char		*name;
}	t_scene;

void	create_scene(t_scene *scene, char *filename);

#endif