#include "libft.h"
#include "MLX42.h"
#include "window_helper.h"

void	window_resized(int32_t width, int32_t height, t_window *window)
{
	ft_printf("Resiziiiing!!!! %ix%i\n\n", width, height);
	window->resize.last_resize = mlx_get_time();
	window->resize.size.width = width;
	window->resize.size.height = height;
	pthread_mutex_lock(&window->image_mutex);
	if (!window->image)
		pthread_mutex_unlock(&window->image_mutex);
	stop_render(&window->render);
	window->image->instances[0].enabled = false;
	pthread_mutex_unlock(&window->image_mutex);
}

int	diff_sizes(t_window_size *a, t_window_size *b)
{
	return (a->width != b->width || a->height != b->height);
}

void	put_image(mlx_image_t *image, mlx_t *mlx)
{
	if (image->count == 0 && mlx_image_to_window(mlx, image, 0, 0) == -1)
		throw_mlx_error("trying to put image to the window",
			mlx_strerror(mlx_errno));
	else
		mlx_resize_image(image, mlx->width, mlx->height);
}
