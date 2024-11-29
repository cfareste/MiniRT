/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_progress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:16:37 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/27 17:13:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/iterators/iterators.h"
#include "loader_progress.h"
#include "../../helpers/loader_helper.h"

t_size	get_bar_size(t_size max)
{
	t_size	bar;

	bar.width = ft_clamp(max.width / 2, 10, max.width);
	bar.height = ft_clamp(max.height / 10, 2, max.height);
	return (bar);
}

void	paint_pixel(t_iterators *it, t_iterators *start, t_loader *loader,
			uint32_t	current)
{
	uint32_t	color;

	color = 0x404040ff;
	if (it->i < start->i + current)
		color = 0xffffffff;
	pthread_mutex_lock(&loader->img_mutex);
	mlx_put_pixel(loader->image, it->i, it->j, color);
	pthread_mutex_unlock(&loader->img_mutex);
}

void	paint_bar(t_loader *loader, t_size img)
{
	t_iterators	it;
	t_size		bar;
	uint32_t	current;
	t_iterators	start;

	bar = get_bar_size(img);
	current = bar.width * get_progress_factor(&loader->progress);
	start.i = img.width / 2 - bar.width / 2;
	start.j = img.height / 2 - bar.height / 2;
	it.i = start.i;
	while (loader_is_alive(loader) && it.i < img.width
		&& it.i < start.i + bar.width)
	{
		it.j = start.j;
		while (loader_is_alive(loader) && it.j < img.height
			&& it.j < start.j + bar.height)
		{
			paint_pixel(&it, &start, loader, current);
			it.j++;
		}
		it.i++;
	}
}
