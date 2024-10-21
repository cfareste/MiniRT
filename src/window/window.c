#include "libft.h"
#include "window.h"
#include "helpers/window_helper.h"
#include "render/render.h"
#include "miniRT.h"

static void	global_hook(t_window *window)
{
	if (window->resize.last_resize
		&& diff_sizes(&window->size, &window->resize.size))
	{
		stop_render(&window->render);
		window->resize.last_resize = 0;
		ft_printf("RENDERING!!!! window: %ix%i; resize: %ix%i\n",
			window->size.width, window->size.height,
			window->resize.size.width, window->resize.size.height);
		window->size = window->resize.size;
		start_render(window);
	}
}

static void	close_window(t_window *window)
{
	stop_render(&window->render);
	mlx_close_window(window->mlx);
}

void	key_hook(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		close_window(window);
	else if (keydata.action == MLX_PRESS
		&& (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F5))
		start_render(window);
}

void	start_window(t_window *window)
{
	pthread_mutex_init(&window->render.render_mutex, NULL);
	pthread_mutex_init(&window->render.loader.current_mutex, NULL);
	pthread_mutex_init(&window->render.loader.total_mutex, NULL);
	pthread_mutex_init(&window->image_mutex, NULL);
	window->size.width = WINDOW_WIDTH;
	window->size.height = WINDOW_HEIGHT;
	window->icon = mlx_load_png(ICON_PATH);
	// mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	window->mlx = mlx_init(window->size.width, window->size.height,
			window->scene.name, true);
	if (window->icon)
		mlx_set_icon(window->mlx, window->icon);
	start_render_loader(&window->render.loader, window->mlx);
	mlx_key_hook(window->mlx,
		(void (*)(mlx_key_data_t keydata, void *)) key_hook, window);
	mlx_resize_hook(window->mlx,
		(void (*)(int, int, void *)) window_resized, window);
	mlx_loop_hook(window->mlx, (void (*)(void *)) global_hook, window);
	mlx_close_hook(window->mlx, (void (*)(void *)) close_window, window);
}
