#include "MLX42.h"
#include "shared/size/size.h"
#include <pthread.h>

t_size	get_image_size(mlx_image_t *image, pthread_mutex_t *mutex)
{
	t_size	size;

	size.width = 0;
	size.height = 0;
	if (mutex)
		pthread_mutex_lock(mutex);
	if (image)
	{
		size.width = image->width;
		size.height = image->height;
	}
	if (mutex)
		pthread_mutex_unlock(mutex);
	return (size);
}

int	is_image_enabled(mlx_image_t *image, pthread_mutex_t *mutex)
{
	int	enabled;

	enabled = 0;
	if (mutex)
		pthread_mutex_lock(mutex);
	if (image && image->count && image->instances)
		enabled = image->instances[image->count - 1].enabled;
	if (mutex)
		pthread_mutex_unlock(mutex);
	return (enabled);
}

void	paint_black_image(mlx_image_t *image, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_put_pixel(image, i, j, 255);
			j++;
		}
		i++;
	}
}
