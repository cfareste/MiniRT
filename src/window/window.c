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
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	window->mlx = mlx_init(window->size.width, window->size.height,
			window->scene.name, true);
	window->image = mlx_new_image(window->mlx, window->size.width, window->size.height);
	mlx_key_hook(window->mlx, key_hook, window);
}
