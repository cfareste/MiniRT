#include "libft.h"
#include "../loader.h"
#include "../helpers/render_loader_helper.h"
#include "helpers/loader_thread_helper.h"
#include "utils/utils.h"

void
	paint_progress_bar(t_loader *loader, int bar_width)
{
	unsigned int	i;
	unsigned int	j;
	t_size			size;
	int				loading;
	int				loader_width;
	int				loader_height;

	size = get_image_size(loader->image, &loader->image_mutex);
	loader_width = get_bar_total_width(size.width);
	loader_height = get_bar_height(size.height);
	loading = is_image_enabled(loader->image, &loader->image_mutex);
	printf("bar width: %d (%f%%)\n\n", bar_width, ((double) bar_width) * 100 / loader_width);
	i = size.width / 2 - loader_width / 2;
	while (loading && i < (size.width / 2 - loader_width / 2) + bar_width)
	{
		j = (size.height / 2 - loader_height / 2);
		while (loading && j < (size.height / 2 - loader_height / 2) + loader_height)
		{
			pthread_mutex_lock(&loader->image_mutex);
			loading = is_image_enabled(loader->image, NULL);
			if (loading && i < loader->image->width && j < loader->image->height)
				mlx_put_pixel(loader->image, i, j, 0xffffffff);
			pthread_mutex_unlock(&loader->image_mutex);
			j++;
		}
		i++;
	}
}

void	*render_loader_routine(t_loader *loader)
{
	int	current;
	int	current_prev;
	int	enabled;
	int	enabled_prev;

	current_prev = 101;
	current = get_current(loader);
	while (loader_thread_alive(loader))
	{
		enabled_prev = enabled;
		enabled = is_image_enabled(loader->image, &loader->image_mutex);
		if (enabled && current_prev != current)
		{
			paint_progress_bar(loader, current);
		}
		if ((!enabled && enabled_prev) || (enabled && current == get_bar_total_width(
				get_image_size(loader->image, &loader->image_mutex).width)
				&& current_prev != current))
		{
			// ft_printf("Painting in black\n\n");
			paint_black_image(loader->image, &loader->image_mutex);
		}
		current_prev = current;
		current = get_bar_width(
					get_image_size(loader->image, &loader->image_mutex).width,
					get_current(loader), get_total(loader));
	}
	set_loader_visibility(loader, false);
	return (NULL);
}
