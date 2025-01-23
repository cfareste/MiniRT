/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:12:16 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 15:54:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_bonus.h"
#include "libft.h"
#include "utils/utils_bonus.h"

static uint8_t	*pixels_dup(uint8_t	*pixels, int amount)
{
	int		i;
	uint8_t	*new;

	new = ft_calloc(1, sizeof(uint8_t) * amount);
	if (!new)
		throw_sys_error("error duplicating image pixels");
	i = 0;
	while (i < amount)
	{
		new[i] = pixels[i];
		i++;
	}
	return (new);
}

t_image	*image_dup(mlx_image_t *image, pthread_mutex_t *mutex)
{
	t_image	*new;

	new = ft_calloc(1, sizeof(t_image));
	if (!new)
		throw_sys_error("error duplicating image");
	new->size = get_image_size(image, mutex);
	if (mutex)
		pthread_mutex_lock(mutex);
	new->pixels = pixels_dup(image->pixels,
			(new->size.width * new->size.height) * 4);
	if (mutex)
		pthread_mutex_unlock(mutex);
	return (new);
}

void	destroy_image(t_image *image)
{
	free(image->pixels);
	free(image);
}
