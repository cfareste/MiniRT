/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 20:21:52 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "MLX42.h"
#include "render/renderer/renderer_bonus.h"

void	window_resized(int32_t width, int32_t height, t_window *window)
{
	window->resize.last_resize = 1;
	window->resize.size.width = width;
	window->resize.size.height = height;
	// stop_render(&window->render);
}

int	diff_sizes(t_size *a, t_size *b)
{
	return (a->width != b->width || a->height != b->height);
}

void	put_image(mlx_image_t *image, mlx_t *mlx, pthread_mutex_t *mutex)
{
	if (mutex)
		pthread_mutex_lock(mutex);
	if (image->count == 0)
		mlx_image_to_window(mlx, image, 0, 0);
	else
		mlx_resize_image(image, mlx->width, mlx->height);
	if (mutex)
		pthread_mutex_unlock(mutex);
}
