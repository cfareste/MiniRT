/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:35:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/05 18:03:23 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector.h"
#include "render/utils/point/point.h"
#include <stdint.h>

float		get_random_float(uint32_t *seed);

void		get_random_point_in_disk(uint32_t *seed, t_vector *vec);

void		get_random_point_in_square(uint32_t *seed, t_vector *vec);

void		get_random_point_in_sphere(uint32_t *seed, t_point *point);

uint32_t	get_random(uint32_t *seed);