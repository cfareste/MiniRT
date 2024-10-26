#pragma once

#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

typedef t_coordinates	t_point;

void	translate_point(t_point *point, t_vector *direction, float scalar,
	t_point *res);
