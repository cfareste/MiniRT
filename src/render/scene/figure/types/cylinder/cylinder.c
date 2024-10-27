#include "libft.h"
#include "utils/utils.h"
#include "render/scene/figure/types/cylinder/helpers/cylinder_helpers.h"
#include <math.h>

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_reference_system	refsys;
	int					hitted;
	float				half_height;

	half_height = figure->cy_attrs->height / 2.0;
	refsys.ray.bounds.min = ray->bounds.min;
	refsys.ray.bounds.max = ray->bounds.max;
	get_vector(&ray->origin, &figure->position, &refsys.ray.origin);
	refsys.ray.direction = ray->direction;
	ft_bzero(&refsys.center, sizeof(t_point));
	rotate_reference_system(&figure->cy_attrs->orientation,
		&refsys.ray.direction, &refsys.ray.origin, &refsys.center);
	hitted = hit_base(&refsys, half_height, figure->cy_attrs->radius, distance);
	hitted |= hit_body(&refsys, figure, ray, distance);
	hitted |= hit_base(&refsys, -half_height, figure->cy_attrs->radius,
			distance);
	return (hitted);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	int			is_base;
	float		point_height;
	t_point		center_offset;
	t_vector	center_to_point;

	is_base = belongs_to_base(point, &figure->position,
			&figure->cy_attrs->orientation, figure->cy_attrs->height);
	if (is_base == 1)
		*res = figure->cy_attrs->orientation;
	else if (is_base == -1)
		multiply_vector_scalar(&figure->cy_attrs->orientation, -1, res);
	else
	{
		get_vector(point, &figure->position, &center_to_point);
		point_height = get_height(point, &figure->position,
				figure->cy_attrs->radius);
		if (dot(&center_to_point, &figure->cy_attrs->orientation) < 0.0)
			point_height *= -1;
		translate_point(&figure->position, &figure->cy_attrs->orientation,
			point_height, &center_offset);
		get_vector(point, &center_offset, res);
		normalize(res);
	}
}

t_figure	*new_cylinder(char **parts)
{
	t_figure	*cylinder;

	if (!parts[1] || !parts[2] || !parts[3] || !parts[4] || !parts[5])
		throw_error("Missing some cylinder parameter");
	cylinder = new_figure(parts[0], parts[1], parts[5]);
	cylinder->cy_attrs = ft_calloc(1, sizeof(t_cylinder_attrs));
	if (!cylinder->cy_attrs)
		throw_sys_error("trying to allocate cylinder attributes");
	set_coordinates(parts[2], &cylinder->cy_attrs->orientation);
	cylinder->cy_attrs->radius = ft_atod(parts[3],
			throw_sys_error, "ft_atod") / 2.0f;
	cylinder->cy_attrs->height = ft_atod(parts[4], throw_sys_error, "ft_atod");
	normalize(&cylinder->cy_attrs->orientation);
	cylinder->print_attrs = print_attrs;
	cylinder->hit = hit;
	cylinder->normal = normal;
	return (cylinder);
}
