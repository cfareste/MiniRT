#pragma once

#include "render/utils/coordinates/coordinates.h"

typedef struct s_bounds
{
	float	max;
	float	min;
}	t_bounds;

typedef struct s_ray
{
	t_coordinates	origin;
	t_coordinates	direction;
	t_bounds		bounds;
}	t_ray;

void	set_ray(t_ray *ray, t_coordinates *origin, t_coordinates *direction);
