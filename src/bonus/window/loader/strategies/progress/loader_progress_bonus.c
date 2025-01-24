/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_progress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:16:37 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/iterators/iterators_bonus.h"
#include "../../helpers/loader_helper_bonus.h"
#include "window/loader/strategies/progress/helpers/loader_progress_helper_bonus.h"

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
