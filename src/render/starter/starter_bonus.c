#include "libft.h"
#include "window/window.h"
#include "render/render.h"
#include "render/helpers/render_helper.h"
#include <pthread.h>

void	stop_render(t_render *render)
{
	if (!render || !render->render)
		return ;
	set_render_finish(render, 1);
	pthread_cancel(render->render);
}

void	*start_routine(t_window *window)
{
	set_render_finish(&window->render, 0);
	if (is_render_finished(&window->render) || !window->image)
		return (NULL);
	render_scene(window);
	return (NULL);
}

void	start_render(t_window *window)
{
	stop_render(&window->render);
	pthread_mutex_lock(&window->image_mutex);
	if (window->image)
		mlx_delete_image(window->mlx, window->image);
	window->image = mlx_new_image(window->mlx, window->size.width,
			window->size.height);
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		throw_mlx_error("trying to write to the window",
			mlx_strerror(mlx_errno));
	pthread_mutex_unlock(&window->image_mutex);
	if (pthread_create(&window->render.render, NULL,
			(void *(*)(void*)) start_routine, (void *) window))
		throw_sys_error("creating new scene render thread");
}
