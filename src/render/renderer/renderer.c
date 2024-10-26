#include "libft.h"
#include "utils/utils.h"
#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "render/render.h"
#include "render/helpers/render_helper.h"
#include "render/loader/helpers/loader_helper/loader_helper.h"
#include <pthread.h>

void	stop_render(t_render *render)
{
	if (!render || !render->thread)
		return ;
	set_render_finish(render, 1);
	set_loader_visibility(&render->loader, false);
}

void	*render_routine(t_render *render)
{
	t_size	size;

	set_render_finish(render, 0);
	if (is_render_finished(render) || !render->image)
		return (NULL);
	size = get_image_size(render->image, &render->image_mutex);
	set_loader_total(&render->loader,
		size.width * size.height);
	render_scene(render, &render->scene,
		get_image_size(render->image, &render->image_mutex));
	if (is_render_finished(render))
		return (NULL);
	pthread_mutex_lock(&render->image_mutex);
	render->image->instances[0].enabled = true;
	pthread_mutex_unlock(&render->image_mutex);
	set_loader_visibility(&render->loader, false);
	return (NULL);
}

void	render(t_render *render, mlx_t *mlx)
{
	stop_render(render);
	pthread_mutex_lock(&render->loader.image_mutex);
	mlx_resize_image(render->loader.image, mlx->width, mlx->height);
	pthread_mutex_unlock(&render->loader.image_mutex);
	set_loader_visibility(&render->loader, true);
	pthread_mutex_lock(&render->image_mutex);
	render->image->instances[0].enabled = false;
	mlx_resize_image(render->image, mlx->width, mlx->height);
	pthread_mutex_unlock(&render->image_mutex);
	if (pthread_create(&render->thread, NULL,
			(void *(*)(void*)) render_routine, (void *) render))
		throw_sys_error("creating new render thread");
	if (pthread_detach(render->thread))
		throw_sys_error("detaching thread");
}
