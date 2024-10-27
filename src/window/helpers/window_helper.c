/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "MLX42.h"
#include "render/renderer/renderer.h"

void	window_resized(int32_t width, int32_t height, t_window *window)
{
	window->resize.last_resize = 1;
	window->resize.size.width = width;
	window->resize.size.height = height;
	stop_render(&window->render);
	pthread_mutex_lock(&window->render.image_mutex);
	if (window->render.image && window->render.image->count)
		window->render.image->instances[0].enabled = false;
	pthread_mutex_unlock(&window->render.image_mutex);
}

int	diff_sizes(t_size *a, t_size *b)
{
	return (a->width != b->width || a->height != b->height);
}

void	put_image(mlx_image_t *image, mlx_t *mlx, pthread_mutex_t *mutex)
{
	if (mutex)
		pthread_mutex_lock(mutex);
	if (image->count == 0 && mlx_image_to_window(mlx, image, 0, 0) == -1)
		throw_mlx_error("trying to put image to the window",
			mlx_strerror(mlx_errno));
	else
		mlx_resize_image(image, mlx->width, mlx->height);
	if (mutex)
		pthread_mutex_unlock(mutex);
}
