#include "libft.h"
#include "MLX42.h"
#include "window_helper.h"

void	window_resized(int32_t width, int32_t height, t_window *window)
{
	window->resize.last_resize = mlx_get_time();
	window->resize.size.width = width;
	window->resize.size.height = height;
	if (!window->image)
		return ;
	stop_renderer(&window->renderer);
	mlx_delete_image(window->mlx, window->image);
}

int	diff_sizes(t_window_size *a, t_window_size *b)
{
	return (a->width != b->width || a->height != b->height);
}
