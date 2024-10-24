#include "libft.h"
#include "render/loader/loader.h"
#include "utils/utils.h"
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

void	set_loader_visibility(t_loader *loader, bool visible)
{
	pthread_mutex_lock(&loader->image_mutex);
	ft_printf("Updating loader: %d\n\n", visible);
	if (loader && loader->image && loader->image->count)
		loader->image->instances[0].enabled = visible;
	pthread_mutex_unlock(&loader->image_mutex);
}

void	update_rend_loader(t_loader *loader, unsigned int current)
{
	pthread_mutex_lock(&loader->current_mutex);
		loader->current = current;
	pthread_mutex_unlock(&loader->current_mutex);
}

void	set_rend_loader_total(t_loader *loader, unsigned int total)
{
	pthread_mutex_lock(&loader->total_mutex);
		loader->total = total;
	pthread_mutex_unlock(&loader->total_mutex);
}
