/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_pixels.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:45:38 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/17 19:12:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "stdint.h"
#include "utils/size/size.h"
#include "utils/iterators/iterators.h"

typedef t_iterators	t_pixel;

t_pixel	*get_random_pixels(t_pixel *pixels, int parts_amount,
			uint32_t *seed, t_size *w_size);

void	fill_pixels(t_size *img_size, t_pixel **pixels_, size_t *px_amount);

void	shuffle_pixels(t_pixel *array, size_t n, uint32_t *seed);