/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_loader_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:19 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/08 23:34:04 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multi_loader_bonus.h"
#include "utils/utils_bonus.h"

static void	*loader_routine(t_multi_loader *loader)
{
	paint_black_image(loader->image, NULL);
	return (NULL);
}

void	loader_show_animation(t_multi_loader *loader, int background,
			t_size size, mlx_t *mlx)
{
	loader->mlx = mlx;
	loader->background = background;
	loader->image = mlx_new_image(mlx, size.width, size.height);
	if (mlx_image_to_window(mlx, loader->image, 0, 0) == -1)
		throw_mlx_error("trying to put loader image to the window",
			mlx_strerror(mlx_errno));
	mlx_image_to_window(mlx, loader->image, 0, 0);
	if (pthread_create(&loader->thread, NULL,
			(void *(*)(void *)) loader_routine, loader) == -1)
		throw_sys_error("creating loader thread");
}

void	loader_hide(t_multi_loader *loader)
{
	pthread_cancel(loader->thread);
	pthread_join(loader->thread, NULL);
	pthread_mutex_lock(&loader->mutex);
	mlx_delete_image(loader->mlx, loader->image);
	pthread_mutex_unlock(&loader->mutex);
}
