#include "libft.h"
#include "window.h"
#include "helpers/window_helper.h"
#include "renderer/renderer.h"
#include "miniRT.h"

static void	global_hook(t_window *window)
{
	if (window->resize.last_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		window->resize.last_resize = 0;
		window->size = window->resize.size;
		start_renderer(window);
	}
}

static void	close_window(t_window *window)
{
	stop_renderer(window);
	mlx_close_window(window->mlx);
}

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		close_window(window);
	else if (keydata.action == MLX_PRESS
		&& (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F5))
		start_renderer(window);
}

void	start_window(t_window *window)
{
	pthread_mutex_init(&window->renderer.render_mutex, NULL);
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	window->icon = mlx_load_png(ICON_PATH);
	window->mlx = mlx_init(window->size.width, window->size.height,
			window->scene.name, true);
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	mlx_key_hook(window->mlx,
		(void (*)(mlx_key_data_t keydata, void *)) key_hook, window);
	mlx_resize_hook(window->mlx,
		(void (*)(int, int, void *)) window_resized, window);
	mlx_loop_hook(window->mlx, (void (*)(void *)) global_hook, window);
	mlx_close_hook(window->mlx, (void (*)(void *)) close_window, window);
}
