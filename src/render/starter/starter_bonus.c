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
	set_loader_visibility(&render->loader, false);
	pthread_cancel(render->render);
}

void	*start_routine(t_window *window)
{
	set_render_finish(&window->render, 0);
	if (is_render_finished(&window->render) || !window->image)
		return (NULL);
	set_rend_loader_total(&window->render.loader,
		window->size.width * window->size.height);
	render_scene(window);
	pthread_mutex_lock(&window->image_mutex);
	window->image->instances[0].enabled = true;
	pthread_mutex_unlock(&window->image_mutex);
	return (NULL);
}

void	start_render(t_window *window)
{
	stop_render(&window->render);
	set_loader_visibility(&window->render.loader, true);
	update_rend_loader(&window->render.loader, 0);
	pthread_mutex_lock(&window->image_mutex);
	if (!window->image)
		window->image = mlx_new_image(window->mlx, window->size.width,
				window->size.height);
	put_image(window->image, window->mlx, NULL);
	window->image->instances[0].enabled = false;
	pthread_mutex_unlock(&window->image_mutex);
	if (pthread_create(&window->render.render, NULL,
			(void *(*)(void*)) start_routine, (void *) window))
		throw_sys_error("creating new render thread");
}
