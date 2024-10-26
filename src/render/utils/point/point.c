#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"

void	translate_point(t_point *point, t_vector *direction, float scalar,
	t_point *res)
{
	res->x = point->x + (scalar * direction->x);
	res->y = point->y + (scalar * direction->y);
	res->z = point->z + (scalar * direction->z);
}
