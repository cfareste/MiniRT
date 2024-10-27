#pragma once

#include "render/scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"

int		hit_body(t_reference_system *refsys, t_figure *cylinder, t_ray *ray,
			float *distance);
