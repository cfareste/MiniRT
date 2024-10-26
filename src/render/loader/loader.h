#pragma once

#define LOADER_HEIGHT_MAX 50
#define LOADER_WIDTH_MAX 1200

#include "MLX42.h"
#include <pthread.h>

typedef struct s_loader
{
	pthread_t		thread;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	unsigned int	total;
	pthread_mutex_t	total_mutex;
	unsigned int	progress;
	pthread_mutex_t	progress_mutex;
	int				thread_finished;
	pthread_mutex_t	thread_finish_mutex;
}	t_loader;

void	destroy_loader(t_loader *loader);

void	set_loader_visibility(t_loader *loader, bool visible);

void	init_loader(t_loader *loader, mlx_t *mlx);
