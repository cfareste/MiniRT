#include "libft.h"
#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "render/render.h"
#include "render/helpers/render_helper.h"
#include "render/loader/helpers/render_loader_helper.h"
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
	update_rend_loader(&window->render.loader, 0);
	render_scene(window);
	pthread_mutex_lock(&window->image_mutex);
	set_loader_visibility(&window->render.loader, false);
	window->image->instances[0].enabled = true;
	pthread_mutex_unlock(&window->image_mutex);
	return (NULL);
}

void	start_render(t_window *window)
{
	stop_render(&window->render);
	update_rend_loader(&window->render.loader, 0);
	pthread_mutex_lock(&window->image_mutex);
	if (!window->image)
		window->image = mlx_new_image(window->mlx, window->size.width,
				window->size.height);
	put_image(window->image, window->mlx);
	window->image->instances[0].enabled = false;
	pthread_mutex_unlock(&window->image_mutex);
	if (pthread_create(&window->render.render, NULL,
			(void *(*)(void*)) start_routine, (void *) window))
		throw_sys_error("creating new render thread");
}
