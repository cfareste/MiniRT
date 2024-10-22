#include "render/loader/loader.h"
int	loader_thread_alive(t_loader *loader)
{
	int	alive;

	pthread_mutex_lock(&loader->thread_finish_mutex);
		alive = !loader->thread_finished;
	pthread_mutex_unlock(&loader->thread_finish_mutex);
	return (alive);
}

void	set_loader_finished(t_loader *loader)
{
	pthread_mutex_lock(&loader->thread_finish_mutex);
	loader->thread_finished = 1;
	pthread_mutex_unlock(&loader->thread_finish_mutex);
}
