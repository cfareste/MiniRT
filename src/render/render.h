#ifndef RENDER_H
# define RENDER_H

# define WIDTH 2000
# define HEIGHT 800
# include "MLX42.h"
# include "shared/coordinates/coordinates.h"
# include "figure/figure.h"
# include "scene/scene.h"

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_coordinates	point;
	t_coordinates	normal;
}	t_hit_record;

void	render_scene(t_scene *scene, mlx_image_t *image, int width, int height);

#endif