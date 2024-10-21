#pragma once
#include "MLX42.h"
#include <pthread.h>

typedef struct s_loader
{
	pthread_t		thread;
	mlx_image_t		*image;
	unsigned int	total;
	pthread_mutex_t	total_mutex;
	unsigned int	current;
	pthread_mutex_t	current_mutex;
}	t_loader;

void	start_render_loader(t_loader *loader, mlx_t *mlx);

