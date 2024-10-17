#include "libft.h"
#include "window.h"
#include "renderer/renderer.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_window	*window;

	window = (t_window *) param;
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		mlx_close_window(window->mlx);
	else if (keydata.key == MLX_KEY_A)
		start_renderer(window);
}

void	start_window(t_window *window)
{
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	window->mlx = mlx_init(window->size.width, window->size.height,
			window->scene.name, true);
	mlx_key_hook(window->mlx, key_hook, window);
}
