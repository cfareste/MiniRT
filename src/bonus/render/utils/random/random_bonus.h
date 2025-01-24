/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:35:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector_bonus.h"
#include "render/utils/point/point_bonus.h"
#include <stdint.h>

float		get_random_float(uint64_t *seed);

void		get_random_point_in_disk(uint64_t *seed, t_vector *vec);

void		get_random_point_in_square(uint64_t *seed, t_vector *vec);

void		get_random_point_in_sphere(uint64_t *seed, t_point *point);

uint64_t	get_random(uint64_t *seed);