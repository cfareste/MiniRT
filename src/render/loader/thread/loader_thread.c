#include "../helpers/bar_helper/bar_helper.h"
#include "../helpers/loader_helper/loader_helper.h"
#include "utils/utils.h"

void	update_progress_bar(t_loader *loader, int bar_width, t_size size)
{
	t_size			bar;
	unsigned int	i;
	unsigned int	j;
	int				loading;

	bar.width = get_bar_total_width(size.width);
	bar.height = get_bar_height(size.height);
	loading = is_image_enabled(loader->image, &loader->image_mutex);
	i = size.width / 2 - bar.width / 2;
	while (loading
		&& i < (size.width / 2 - bar.width / 2) + bar_width)
	{
		j = (size.height / 2 - bar.height / 2);
		while (loading && j < (size.height / 2 - bar.height / 2) + bar.height)
		{
			pthread_mutex_lock(&loader->image_mutex);
			loading = is_image_enabled(loader->image, NULL);
			if (loading
				&& i < loader->image->width && j < loader->image->height)
				mlx_put_pixel(loader->image, i, j, 0xffffffff);
			pthread_mutex_unlock(&loader->image_mutex);
			j++;
		}
		i++;
	}
}

static int	is_loader_thread_alive(t_loader *loader)
{
	int	alive;

	pthread_mutex_lock(&loader->thread_finish_mutex);
	alive = !loader->thread_finished;
	pthread_mutex_unlock(&loader->thread_finish_mutex);
	return (alive);
}

void	*loader_routine(t_loader *loader)
{
	unsigned int	current;
	unsigned int	current_prev;
	int				enabled;
	int				enabled_prev;

	current = 101;
	while (is_loader_thread_alive(loader))
	{
		enabled_prev = enabled;
		enabled = is_image_enabled(loader->image, &loader->image_mutex);
		current_prev = current;
		current = get_bar_width(
				get_image_size(loader->image, &loader->image_mutex).width,
				get_loader_progress(loader), get_loader_total(loader));
		if (enabled != enabled_prev
			|| (current == 0 && current != current_prev))
			paint_black_image(loader->image, &loader->image_mutex);
		else if (enabled && current != current_prev)
			update_progress_bar(loader, current,
				get_image_size(loader->image, &loader->image_mutex));
	}
	set_loader_visibility(loader, false);
	return (NULL);
}

void	kill_loader_routine(t_loader *loader)
{
	pthread_mutex_lock(&loader->thread_finish_mutex);
	loader->thread_finished = 1;
	pthread_mutex_unlock(&loader->thread_finish_mutex);
}
