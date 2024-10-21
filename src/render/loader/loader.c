#include "libft.h"
#include "window/window.h"
#include "window/helpers/window_helper.h"
#include "helpers/render_loader_helper.h"

void	*render_loader_routine(t_loader *loader)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	current;
	unsigned int	current_prev;

	(void) j;
	current_prev = 101;
	current = get_current(loader);
	while (42)
	{
		i = 0;
		while (loader->image && i < loader->image->width)
		{
			j = 0;
			while (loader->image && j < loader->image->height)
			{
				mlx_put_pixel(loader->image, i, j, 255);
				j++;
			}
			i++;
		}
		loader->image->instances[0].enabled = true;
		current = get_current(loader);
		current_prev = current;
	}
	set_loader_visibility(loader, false);
	return (NULL);
}

void	start_render_loader(t_loader *loader, mlx_t *mlx)
{
	if (!loader->image)
		loader->image = mlx_new_image(mlx, mlx->width,
				mlx->height);
	loader->total = 100;
	put_image(loader->image, mlx);
	if (pthread_create(&loader->thread, NULL,
		(void *(*)(void *)) render_loader_routine, loader) == -1)
		throw_sys_error("creating new render thread");
}
