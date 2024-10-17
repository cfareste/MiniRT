#include "libft.h"
#include "window.h"
#include "render/render.h"

// TODO: Create a loader
// TODO: Protect ft_split()!

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_window	*window;

	window = (t_window *) param;
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		mlx_close_window(window->mlx);
}

void	start_window(t_window *window)
{
	window->width = WINDOW_WIDTH;
	window->height = WINDOW_HEIGHT;
	window->mlx = mlx_init(window->width, window->height,
			window->scene.name, true);
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	mlx_key_hook(window->mlx, key_hook, window);
}
