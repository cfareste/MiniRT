/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:19 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/21 20:12:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loader_bonus.h"
#include "utils/utils_bonus.h"
#include "window/helpers/window_helper_bonus.h"

static void	*loader_routine(t_loader *loader)
{
	(void) loader;
	return (NULL);
}

void	loader_show_animation(t_loader *loader, int background,
			t_size size)
{
	loader->background = background;
	mlx_resize_image(loader->image, size.width, size.height);
	if (pthread_create(&loader->thread, NULL,
			(void *(*)(void *)) loader_routine, loader) == -1)
		throw_sys_error("creating loader thread");
}

void	loader_hide(t_loader *loader)
{
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
}

void	init_loader(t_loader *loader, mlx_t *mlx)
{
	pthread_mutex_init(&loader->mutex, NULL);
	loader->mlx = mlx;
	loader->image = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, loader->image, 0, 0);
	mlx_set_instance_depth(loader->image->instances
		+ loader->image->count - 1, 1);
}
