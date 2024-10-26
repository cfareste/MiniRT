#include "utils/utils.h"
#include "window/helpers/window_helper.h"
#include "thread/loader_thread.h"

void	destroy_loader(t_loader *loader)
{
	set_loader_visibility(loader, false);
	kill_loader_routine(loader);
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
}

void	set_loader_visibility(t_loader *loader, bool visible)
{
	pthread_mutex_lock(&loader->image_mutex);
	if (loader && loader->image && loader->image->count)
		loader->image->instances[0].enabled = visible;
	pthread_mutex_unlock(&loader->image_mutex);
	pthread_mutex_lock(&loader->progress_mutex);
	loader->progress = 0;
	pthread_mutex_unlock(&loader->progress_mutex);
}

void	init_loader(t_loader *loader, mlx_t *mlx)
{
	pthread_mutex_init(&loader->progress_mutex, NULL);
	pthread_mutex_init(&loader->total_mutex, NULL);
	pthread_mutex_init(&loader->image_mutex, NULL);
	pthread_mutex_init(&loader->thread_finish_mutex, NULL);
	loader->total = 100;
	loader->progress = 0;
	loader->image = mlx_new_image(mlx, mlx->width,
			mlx->height);
	paint_black_image(loader->image, NULL);
	put_image(loader->image, mlx, NULL);
	if (pthread_create(&loader->thread, NULL,
			(void *(*)(void *)) loader_routine, loader) == -1)
		throw_sys_error("creating loader thread");
}
