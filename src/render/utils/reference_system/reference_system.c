#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	rotate_reference_system(t_vector *normal, t_vector *vec,
	t_point *point, t_point *center)
{
	t_vector	ideal;
	t_vector	axis;
	float		angle;

	get_axis(&ideal, BACK);
	cross(normal, &ideal, &axis);
	if (axis.x == 0.0 && axis.y == 0.0 && axis.z == 0.0)
		return ;
	normalize(&axis);
	angle = acos(dot(normal, &ideal));
	rotate_vector(vec, &axis, angle, vec);
	rotate_vector(point, &axis, angle, point);
	rotate_vector(center, &axis, angle, center);
}
