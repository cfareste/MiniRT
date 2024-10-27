#include "libft.h"
#include "utils/utils.h"
#include "coordinates.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <math.h>

void	rotate_reference_system(t_coordinates *normal, t_coordinates *vec,
	t_coordinates *point, t_coordinates *center)
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

void	set_coordinates(char *str, t_coordinates *coordinates)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts)
		throw_sys_error("ft_split");
	if (!parts[0] || !parts[1] || !parts[2])
		throw_error("Missing some coordinates param");
	coordinates->x = ft_atod(parts[0], throw_sys_error, "ft_atod");
	coordinates->y = ft_atod(parts[1], throw_sys_error, "ft_atod");
	coordinates->z = ft_atod(parts[2], throw_sys_error, "ft_atod");
	free_matrix(parts);
}
