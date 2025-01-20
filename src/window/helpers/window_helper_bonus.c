/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 15:54:57 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "MLX42.h"
#include "render/renderer/renderer_bonus.h"

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

t_window	*get_window(t_window *window)
{
	static t_window	*ctx = NULL;

	if (window)
		ctx = window;
	return (ctx);
}
