#include "libft.h"
#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "helpers/render_loader_helper.h"
#include "thread/helpers/loader_thread_helper.h"
#include "render/helpers/render_helper.h"
#include "utils/utils.h"
#include "thread/loader_thread.h"

void	rend_loader_tick(t_loader *loader)
{
	pthread_mutex_lock(&loader->current_mutex);
	loader->current += 1;
	pthread_mutex_unlock(&loader->current_mutex);
}

void	destroy_rend_loader(t_loader *loader)
{
	set_loader_visibility(loader, false);
	set_loader_finished(loader);
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
}

void	init_render_loader(t_loader *loader, mlx_t *mlx)
{
	if (!loader->image)
		loader->image = mlx_new_image(mlx, mlx->width,
				mlx->height);
	paint_black_image(loader->image, NULL);
	pthread_mutex_init(&loader->current_mutex, NULL);
	pthread_mutex_init(&loader->total_mutex, NULL);
	pthread_mutex_init(&loader->image_mutex, NULL);
	pthread_mutex_init(&loader->thread_finish_mutex, NULL);
	loader->total = 100;
	loader->current = 0;
	put_image(loader->image, mlx, NULL);
	if (pthread_create(&loader->thread, NULL,
		(void *(*)(void *)) render_loader_routine, loader) == -1)
		throw_sys_error("creating new render thread");
}
