#pragma once

#include "render/scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"

float	get_height(t_point *point, t_point *center, float base);

int		belongs_to_base(t_point *point, t_point *center, t_vector *normal,
			float height);

int		hit_base(t_reference_system *refsys, float base_center_distance,
			float radius, float *distance);

int		hit_body(t_reference_system *refsys, t_figure *cylinder, t_ray *ray,
			float *distance);
