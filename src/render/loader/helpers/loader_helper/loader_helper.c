#include "../../loader.h"

void	add_loader_progress(t_loader *loader)
{
	pthread_mutex_lock(&loader->progress_mutex);
	loader->progress += 1;
	pthread_mutex_unlock(&loader->progress_mutex);
}

unsigned int	get_loader_progress(t_loader *loader)
{
	unsigned int	current;

	pthread_mutex_lock(&loader->progress_mutex);
	current = loader->progress;
	pthread_mutex_unlock(&loader->progress_mutex);
	return (current);
}

void	set_loader_progress(t_loader *loader, unsigned int current)
{
	pthread_mutex_lock(&loader->progress_mutex);
	loader->progress = current;
	pthread_mutex_unlock(&loader->progress_mutex);
}

unsigned int	get_loader_total(t_loader *loader)
{
	unsigned int	total;

	pthread_mutex_lock(&loader->total_mutex);
	total = loader->total;
	pthread_mutex_unlock(&loader->total_mutex);
	return (total);
}

void	set_loader_total(t_loader *loader, unsigned int total)
{
	pthread_mutex_lock(&loader->total_mutex);
	loader->total = total;
	pthread_mutex_unlock(&loader->total_mutex);
}
