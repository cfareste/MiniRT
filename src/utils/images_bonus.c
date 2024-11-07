/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:49 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 15:18:01 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "utils/size/size.h"
#include "render/loader/loader_bonus.h"
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

static void	paint_background_pixel(mlx_image_t *image, pthread_mutex_t *mutex,
	t_size size, t_size curr_size)
{
	t_size	loader_size;
	t_size	min_size;
	t_size	max_size;
	int		color;

	loader_size.width = ft_clamp(size.width / 2, 10, LOADER_WIDTH_MAX);
	loader_size.height = ft_clamp(size.height / 20, 2, LOADER_HEIGHT_MAX);
	min_size.width = (size.width / 2 - loader_size.width / 2);
	min_size.height = (size.height / 2 - loader_size.height / 2);
	max_size.width = (size.width / 2 - loader_size.width / 2)
		+ loader_size.width;
	max_size.height = (size.height / 2 - loader_size.height / 2)
		+ loader_size.height;
	color = 255;
	if (curr_size.width >= min_size.width && curr_size.width < max_size.width
		&& curr_size.height >= min_size.height
		&& curr_size.height < max_size.height)
		color = 0x404040ff;
	if (mutex)
		pthread_mutex_lock(mutex);
	if (!mutex || (curr_size.width < image->width
			&& curr_size.height < image->height))
		mlx_put_pixel(image, curr_size.width, curr_size.height, color);
	if (mutex)
		pthread_mutex_unlock(mutex);
}

void	paint_black_image(mlx_image_t *image, pthread_mutex_t *mutex)
{
	t_size			size;
	t_size			curr_size;

	size = get_image_size(image, mutex);
	curr_size.width = 0;
	while (curr_size.width < size.width)
	{
		size = get_image_size(image, mutex);
		curr_size.height = 0;
		while (curr_size.height < size.height)
		{
			paint_background_pixel(image, mutex, size, curr_size);
			curr_size.height++;
		}
		curr_size.width++;
	}
}
