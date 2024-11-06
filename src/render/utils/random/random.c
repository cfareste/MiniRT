#include "render/utils/vector/vector.h"
#include <stdint.h>
#include <math.h>

float	get_random_float(uint32_t *seed)
{
	*seed ^= *seed << 13;
	*seed ^= *seed >> 17;
	*seed ^= *seed << 5;
	return (*seed / (float) UINT32_MAX);
}

void	get_random_point_in_disk(uint32_t *seed, t_vector *vec)
{
	while (42)
	{
		vec->x = get_random_float(seed) - 0.5;
		vec->y = get_random_float(seed) - 0.5;
		vec->z = 0.0;
		if (sqrt(dot(vec, vec)) < 1.0)
			return ;
	}
}

void	get_random_point_in_square(uint32_t *seed, t_vector *vec)
{
	vec->x = get_random_float(seed) - 0.5;
	vec->y = get_random_float(seed) - 0.5;
}