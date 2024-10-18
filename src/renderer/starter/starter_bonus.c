#include "libft.h"
#include "window/window.h"
#include "renderer/renderer.h"
#include <pthread.h>

// static void	stop_renderer(t_renderer *renderer)
// {
// 	if (renderer && renderer->render)
// 		pthread_cancel(renderer->render);
// }

// TODO: Loader!!
static void	start_routine(t_window *window)
{
	ft_printf("RENDERING (%ld)\n\n", window->renderer.render);
	window->image = mlx_new_image(window->mlx, window->size.width,
			window->size.height);
	render_scene(window);
	if (mlx_image_to_window(window->mlx, window->image, 0, 0))
		throw_sys_error("trying to write to the window");
}

void	start_renderer(t_window *window)
{
	// stop_renderer(&window->renderer);
	// if (window->image)
	// 	mlx_delete_image(window->mlx, window->image);
	// if (pthread_create(&window->renderer.render, NULL, (void *(*)(void *)) start_routine, window))
	// 	throw_sys_error("creating new scene render thread");

	start_routine(window);
}
