/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_progress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:16:37 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/03 18:19:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/iterators/iterators.h"
#include "loader_progress.h"
#include "../../helpers/loader_helper.h"

void	paint_pixel(t_iterators *it, t_loader *loader,
			uint32_t	current)
{
	uint32_t	color;

	color = 0x404040ff;
	if (it->i < current)
		color = 0xffffffff;
	pthread_mutex_lock(&loader->img_mutex);
	mlx_put_pixel(loader->image, it->i, it->j, color);
	pthread_mutex_unlock(&loader->img_mutex);
}

void	paint_bar(t_loader *loader, t_size img)
{
	t_iterators	it;
	uint32_t	current;

	current = img.width * get_progress_factor(&loader->progress);
	it.i = 0;
	while (loader_is_alive(loader) && it.i < img.width)
	{
		it.j = 0;
		while (loader_is_alive(loader) && it.j < img.height)
		{
			paint_pixel(&it, loader, current);
			it.j++;
		}
		it.i++;
	}
}
