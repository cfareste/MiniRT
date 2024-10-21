#include "libft.h"
#include "MLX42.h"
#include "window_helper.h"

void	window_resized(int32_t width, int32_t height, t_window *window)
{
	window->resize.last_resize = mlx_get_time();
	window->resize.size.width = width;
	window->resize.size.height = height;
	pthread_mutex_lock(&window->image_mutex);
	if (window->image)
	{
		stop_render(&window->render);
		mlx_delete_image(window->mlx, window->image);
	}
	pthread_mutex_unlock(&window->image_mutex);
}

int	diff_sizes(t_window_size *a, t_window_size *b)
{
	return (a->width != b->width || a->height != b->height);
}
