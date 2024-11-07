/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:35:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/06 18:35:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector.h"
#include <stdint.h>

float	get_random_float(uint32_t *seed);

void	get_random_point_in_disk(uint32_t *seed, t_vector *vec);

void	get_random_point_in_square(uint32_t *seed, t_vector *vec);
