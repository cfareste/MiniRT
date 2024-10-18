#include "libft.h"
#include "window.h"
#include "renderer/renderer.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_window	*window;

	window = (t_window *) param;
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		mlx_close_window(window->mlx);
	else if (keydata.action == MLX_PRESS
		&& (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F5))
		start_renderer(window);
}

void	start_window(t_window *window)
{
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	window->icon = mlx_load_png(ICON_PATH);
	mlx_set_setting(MLX_MAXIMIZED, 1);
	window->mlx = mlx_init(window->size.width, window->size.height,
			window->scene.name, true);
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	mlx_key_hook(window->mlx, key_hook, window);
	// mlx_set_icon(mlx_t* mlx, mlx_texture_t* image);
}
