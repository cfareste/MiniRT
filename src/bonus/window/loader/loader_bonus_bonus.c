/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_bonus_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:19 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "loader_bonus_bonus.h"
#include "utils/utils_bonus_bonus.h"
#include "helpers/loader_helper_bonus.h"
#include "load/load_bonus.h"

void	loader_hide(t_loader *loader)
{
	loader_set_alive(loader, 0);
	loader_set_img_enabled(loader, 0);
	pthread_cancel(loader->thread);
	if (loader->thread)
		pthread_join(loader->thread, NULL);
	loader->thread = 0;
}

void	init_loader(t_loader *loader, t_jobs *jobs, mlx_t *mlx, t_size *w_size)
{
	pthread_mutex_init(&loader->img_mutex, NULL);
	pthread_mutex_init(&loader->alive_mutx, NULL);
	pthread_mutex_init(&loader->progress.mutex, NULL);
	pthread_mutex_init(&loader->resize_mutx, NULL);
	loader->resize = 1;
	loader->jobs = jobs;
	loader->mlx = mlx;
	loader->w_size = w_size;
	loader->image = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, loader->image, LOADER_POS, LOADER_POS);
	mlx_set_instance_depth(loader->image->instances
		+ loader->image->count - 1, 1);
}

void	loader_update_size(t_loader *loader)
{
	t_size	w_size;

	w_size = get_size(loader->w_size);
	pthread_mutex_lock(&loader->img_mutex);
	loader->size.width = ft_clamp(w_size.width / 2 - LOADER_POS,
			MIN_LOADER_MINI_WIDTH, MAX_LOADER_MINI_WIDTH);
	loader->size.height = ft_clamp(w_size.height / 10,
			MIN_LOADER_MINI_HEIGHT, MAX_LOADER_MINI_HEIGHT);
	pthread_mutex_unlock(&loader->img_mutex);
}

// TODO: Check malloc nullcheck!
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

void	loader_toggle_visibility(t_loader *loader)
{
	int	actual;

	if (!loader_is_alive(loader))
		return ;
	pthread_mutex_lock(&loader->img_mutex);
	actual = loader->image->enabled;
	pthread_mutex_unlock(&loader->img_mutex);
	loader_set_img_enabled(loader, !actual);
}
