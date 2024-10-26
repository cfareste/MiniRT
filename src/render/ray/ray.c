#include "ray.h"
#include "float.h"
#include "render/utils/vector/vector.h"

void	set_ray(t_ray *ray, t_coordinates *origin, t_coordinates *direction)
{
	ray->bounds.min = 0.01;
	ray->bounds.max = FLT_MAX;
	ray->origin = *origin;
	ray->direction = *direction;
	normalize(&ray->direction);
}
