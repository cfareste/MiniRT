#pragma once
#include "MLX42.h"
#include <pthread.h>
#define LOADER_HEIGHT 50
#define LOADER_WIDTH 200

typedef struct s_loader
{
	pthread_t		thread;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	unsigned int	total;
	pthread_mutex_t	total_mutex;
	unsigned int	current;
	pthread_mutex_t	current_mutex;
	int				thread_finished;
	pthread_mutex_t	thread_finish_mutex;
}	t_loader;

void	init_render_loader(t_loader *loader, mlx_t *mlx);

void	destroy_rend_loader(t_loader *loader);

void	rend_loader_tick(t_loader *loader);
