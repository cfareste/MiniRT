/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:35:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/16 18:11:24 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector.h"
#include "render/utils/point/point.h"
#include <stdint.h>

float		get_random_float(uint64_t *seed);

void		get_random_point_in_disk(uint64_t *seed, t_vector *vec);

void		get_random_point_in_square(uint64_t *seed, t_vector *vec);

void		get_random_point_in_sphere(uint64_t *seed, t_point *point);

uint64_t	get_random(uint64_t *seed);