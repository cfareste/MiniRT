/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 17:11:48 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "thread/loader_thread_bonus.h"

void	destroy_loader(t_loader *loader)
{
	set_loader_visibility(loader, false);
	kill_loader_routine(loader);
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
}

void	set_loader_visibility(t_loader *loader, bool visible)
{
	pthread_mutex_lock(&loader->image_mutex);
	if (loader && loader->image && loader->image->count)
		loader->image->instances[0].enabled = visible;
	pthread_mutex_unlock(&loader->image_mutex);
}

void	init_loader(t_loader *loader, mlx_t *mlx)
{
	pthread_mutex_init(&loader->progress_mutex, NULL);
	pthread_mutex_init(&loader->total_mutex, NULL);
	pthread_mutex_init(&loader->image_mutex, NULL);
	pthread_mutex_init(&loader->thread_finish_mutex, NULL);
	loader->total = 100;
	loader->progress = 0;
	loader->image = mlx_new_image(mlx, mlx->width,
			mlx->height);
	paint_black_image(loader->image, NULL);
	put_image(loader->image, mlx, NULL);
	if (pthread_create(&loader->thread, NULL,
			(void *(*)(void *)) loader_routine, loader) == -1)
		throw_sys_error("creating loader thread");
}
