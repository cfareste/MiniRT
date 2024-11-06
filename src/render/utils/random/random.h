#pragma once

#include "render/utils/vector/vector.h"
#include <stdint.h>

float	get_random_float(uint32_t *seed);

void	get_random_point_in_disk(uint32_t *seed, t_vector *vec);

void	get_random_point_in_square(uint32_t *seed, t_vector *vec);
