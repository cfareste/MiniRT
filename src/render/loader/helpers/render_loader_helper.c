#include "render/loader/loader.h"
#include <pthread.h>

unsigned int	get_current(t_loader *loader)
{
	unsigned int	current;
	pthread_mutex_lock(&loader->current_mutex);
		current = loader->current;
	pthread_mutex_unlock(&loader->current_mutex);
	return (current);
}

unsigned int	get_total(t_loader *loader)
{
	unsigned int	total;
	pthread_mutex_lock(&loader->total_mutex);
		total = loader->total;
	pthread_mutex_unlock(&loader->total_mutex);
	return (total);
}

void	set_loader_visibility(t_loader *loader, bool shown)
{
	if (loader && loader->image && loader->image->count)
		loader->image->instances[0].enabled = shown;
}

void	update_rend_loader(t_loader *loader, unsigned int current)
{
	set_loader_visibility(loader, true);
	pthread_mutex_lock(&loader->current_mutex);
		loader->current = current;
	pthread_mutex_unlock(&loader->current_mutex);
	pthread_mutex_lock(&loader->total_mutex);
	if (current == loader->total)
		set_loader_visibility(loader, false);
	pthread_mutex_unlock(&loader->total_mutex);
}

void	set_rend_loader_total(t_loader *loader, unsigned int total)
{
	pthread_mutex_lock(&loader->total_mutex);
		loader->total = total;
	pthread_mutex_unlock(&loader->total_mutex);
}
