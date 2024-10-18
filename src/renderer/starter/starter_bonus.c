#include "libft.h"
#include "window/window.h"
#include "renderer/renderer.h"
#include "renderer/helpers/render_helper.h"
#include <pthread.h>

void	stop_renderer(t_renderer *renderer)
{
	if (!renderer || !renderer->render)
		return ;
	pthread_cancel(renderer->render);
	set_render_finish(renderer, 1);
}

void	*start_routine(t_window *window)
{
	if (is_render_finished(&window->renderer))
		return (NULL);
	render_scene(window);
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		throw_mlx_error("trying to write to the window",
			mlx_strerror(mlx_errno));
	return (NULL);
}

void	start_renderer(t_window *window)
{
	stop_renderer(&window->renderer);
	if (window->image)
		mlx_delete_image(window->mlx, window->image);
	window->image = mlx_new_image(window->mlx, window->size.width,
			window->size.height);
	set_render_finish(&window->renderer, 0);
	if (pthread_create(&window->renderer.render, NULL,
			(void *(*)(void*)) start_routine, (void *) window))
		throw_sys_error("creating new scene render thread");
}
