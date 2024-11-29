/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:19 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/27 20:08:55 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "loader_bonus.h"
#include "utils/utils_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "helpers/loader_helper.h"
#include "load/load.h"

void	loader_hide(t_loader *loader)
{
	(void) loader;
	loader_set_alive(loader, 0);
	loader_set_img_enabled(loader, 0);
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
	printf("Not loading anymore\n\n");
}

void	init_loader(t_loader *loader, t_jobs *jobs, mlx_t *mlx)
{
	pthread_mutex_init(&loader->img_mutex, NULL);
	pthread_mutex_init(&loader->alive_mutx, NULL);
	pthread_mutex_init(&loader->progress.mutex, NULL);
	pthread_mutex_init(&loader->resize_mutx, NULL);
	loader->resize = 1;
	loader->jobs = jobs;
	loader->mlx = mlx;
	loader->image = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, loader->image, 0, 0);
	mlx_set_instance_depth(loader->image->instances
		+ loader->image->count - 1, 1);
}

void	loader_update_size(t_loader *loader)
{
	pthread_mutex_lock(&loader->img_mutex);
	if (loader->lsize == LOADER_SIZE_FULL)
	{
		loader->size.width = loader->mlx->width;
		loader->size.height = loader->mlx->height;
	}
	else
	{
		loader->size.width = ft_clamp(loader->mlx->width / 2,
				MIN_LOADER_MINI_WIDTH, MAX_LOADER_MINI_WIDTH);
		loader->size.height = ft_clamp(loader->mlx->height / 2,
				MIN_LOADER_MINI_HEIGHT, MAX_LOADER_MINI_HEIGHT);
	}
	pthread_mutex_unlock(&loader->img_mutex);
}

void	loader_show(t_loader *loader, t_loader_mode mode, t_loader_size size)
{
	t_load	*load;

	if (loader_is_alive(loader))
		loader_hide(loader);
	loader_set_alive(loader, 1);
	load = new_loader_load(loader);
	if (!load)
		write(2, "Loader not being shown!\n", 24);
	loader->lsize = size;
	loader->mode = mode;
	if (!loader_is_alive(loader))
	{
		free(load);
		return ;
	}
	if (pthread_create(&loader->thread, NULL,
			(void *(*)(void *)) minirt_load_routine, load) == -1)
		throw_sys_error("creating loader thread");
}
