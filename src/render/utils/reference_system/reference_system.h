#pragma once

#include "render/ray/ray.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"

typedef struct s_reference_system
{
	t_ray	ray;
	t_point	center;
}	t_reference_system;

void	rotate_reference_system(t_vector *normal, t_vector *vec,
			t_point *point, t_point *center);
