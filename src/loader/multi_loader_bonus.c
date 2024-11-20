/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_loader_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:19 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/20 20:08:29 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multi_loader_bonus.h"
#include "utils/utils_bonus.h"
#include "window/helpers/window_helper_bonus.h"

static void	*loader_routine(t_multi_loader *loader)
{
	(void) loader;
	// if (loader->background)
	// 	paint_black_image(loader->image, NULL);
	return (NULL);
}

void	loader_show_animation(t_multi_loader *loader, int background,
			t_size size)
{
	loader->background = background;
	mlx_resize_image(loader->image, size.width, size.height);
	if (pthread_create(&loader->thread, NULL,
			(void *(*)(void *)) loader_routine, loader) == -1)
		throw_sys_error("creating loader thread");
}

void	loader_hide(t_multi_loader *loader)
{
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
}

void	init_multi_loader(t_multi_loader *loader, mlx_t *mlx)
{
	pthread_mutex_init(&loader->mutex, NULL);
	loader->mlx = mlx;
	loader->image = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, loader->image, 0, 0);
}
