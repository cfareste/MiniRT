/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:45:45 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/16 18:13:15 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "renderer_pixels.h"
#include "render/utils/random/random.h"
#include <stdio.h>
#include <limits.h>

void	shuffle_pixels(t_pixel *array, size_t n, uint64_t *seed)
{
	size_t		i;
	size_t		j;
	t_pixel		aux;

	if (n <= 1)
		return ;
	i = 0;
	while (i < n - 1)
	{
		j = i + get_random(seed) / (UINT64_MAX / (n - i) + 1);
		aux = array[j];
		array[j] = array[i];
		array[i] = aux;
		i++;
	}
}

// TODO: Test times with realloc
void	fill_pixels(t_size img_size, t_pixel **pixels_, size_t *px_amount)
{
	t_iterators	iter;
	t_pixel		*pixels;

	printf("Filling pixels\n");
	free(*pixels_);
	*pixels_ = ft_calloc((img_size.width * img_size.height) + 1,
			sizeof(t_pixel));
	if (!*pixels_)
		throw_sys_error("alloc pixels");
	pixels = *pixels_;
	*px_amount = 0;
	iter.i = 0;
	while (iter.i < img_size.width)
	{
		iter.j = 0;
		while (iter.j < img_size.height)
		{
			pixels[*px_amount] = iter;
			(*px_amount)++;
			iter.j++;
		}
		iter.i++;
	}
}
