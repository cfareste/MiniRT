#include "libft.h"
#include "../loader.h"
#include "../helpers/render_loader_helper.h"
#include "helpers/loader_thread_helper.h"
#include "utils/utils.h"

void
	paint_progress(t_loader *loader, unsigned int current, unsigned int total)
{
	unsigned int	i;
	unsigned int	j;
	t_size			size;
	int				loading;
	int				bar_width;
	int				loader_width;
	int				loader_height;

	size = get_image_size(loader->image, &loader->image_mutex);
	loader_width = size.width / 2;
	loader_height = ft_normalize(size.height / 20, 2, LOADER_HEIGHT);
	bar_width = (loader_width * (current * 100 / total)) / 100;
	loading = is_image_enabled(loader->image, &loader->image_mutex);
	ft_printf("bar width: %d {current: %d, total: %d, %%: %d}\n\n", bar_width, current, total, current * 100 / total);
	i = 0;
	while (loading && i < size.width)
	{
		j = 0;
		while (loading && j < size.height)
		{
			if (i >= (size.width / 2 - loader_width / 2) && i < (size.width / 2 - loader_width / 2) + bar_width
				&& j >= (size.height / 2 - loader_height / 2) && j < (size.height / 2 - loader_height / 2) + loader_height)
			{
				pthread_mutex_lock(&loader->image_mutex);
				loading = is_image_enabled(loader->image, NULL);
				if (loading && i < loader->image->width && j < loader->image->height)
					mlx_put_pixel(loader->image, i, j, 0xffffffff);
				pthread_mutex_unlock(&loader->image_mutex);
			}
			else
			{
				pthread_mutex_lock(&loader->image_mutex);
				loading = is_image_enabled(loader->image, NULL);
				if (loading && i < loader->image->width && j < loader->image->height)
					mlx_put_pixel(loader->image, i, j, 255);
				pthread_mutex_unlock(&loader->image_mutex);
			}
			j++;
		}
		i++;
	}
}

void	*render_loader_routine(t_loader *loader)
{
	unsigned int	current;
	unsigned int	current_prev;
	int				enabled;
	int				enabled_prev;

	current_prev = 101;
	current = get_current(loader);
	while (loader_thread_alive(loader))
	{
		enabled_prev = enabled;
		enabled = is_image_enabled(loader->image, &loader->image_mutex);
		if (enabled && current_prev != current)
		{
			paint_progress(loader, get_current(loader), get_total(loader));
		}
		if ((!enabled && enabled_prev) || (enabled && current == get_total(loader) && current_prev != current))
		{
			ft_printf("Painting in black\n\n");
			paint_black_image(loader->image, &loader->image_mutex);
		}
		current_prev = current;
		current = get_current(loader);
	}
	set_loader_visibility(loader, false);
	return (NULL);
}
