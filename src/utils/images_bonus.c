/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:49 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 19:51:27 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "utils/size/size.h"
#include "window/helpers/window_helper_bonus.h"
#include <pthread.h>

t_size	get_image_size(mlx_image_t *image, pthread_mutex_t *mutex)
{
	t_size	size;

	size.width = 0;
	size.height = 0;
	if (mutex)
		pthread_mutex_lock(mutex);
	if (image)
	{
		size.width = image->width;
		size.height = image->height;
	}
	if (mutex)
		pthread_mutex_unlock(mutex);
	return (size);
}

int	is_image_enabled(mlx_image_t *image, pthread_mutex_t *mutex)
{
	int	enabled;

	enabled = 0;
	if (mutex)
		pthread_mutex_lock(mutex);
	if (image && image->count && image->instances)
		enabled = image->instances[image->count - 1].enabled;
	if (mutex)
		pthread_mutex_unlock(mutex);
	return (enabled);
}
