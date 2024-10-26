#pragma once
#include "MLX42.h"
#include "render/utils/coordinates/coordinates.h"
#include "render/scene/scene.h"
#include "loader/loader.h"

typedef struct s_render
{
	t_scene			scene;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	pthread_t		thread;
	t_loader		loader;
	int				finished;
	pthread_mutex_t	render_mutex;
}	t_render;

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_coordinates	point;
	t_coordinates	normal;
}	t_hit_record;

void	render_scene(t_render *render, t_scene *scene, t_size size);

void	init_render(t_render *render, mlx_t *mlx);