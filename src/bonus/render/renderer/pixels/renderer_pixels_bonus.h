/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_pixels_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:45:38 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 12:05:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils/size/size_bonus.h"
#include "utils/iterators/iterators_bonus.h"
#include <stdint.h>

typedef t_iterators	t_pixel;

t_pixel	*get_random_pixels(t_pixel *pixels, int parts_amount,
			uint64_t *seed, t_size *w_size);

void	fill_pixels(t_size img_size, t_pixel **pixels_, size_t *px_amount);

void	shuffle_pixels(t_pixel *array, size_t n, uint64_t *seed);