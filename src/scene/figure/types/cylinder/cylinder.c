#include "scene/figure/figure.h"
#include "libft.h"
#include "utils/utils.h"
#include "shared/coordinates/coordinates.h"

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->diameter, attrs->height);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	(void) figure;
	(void) ray;
	(void) distance;
	return (0);
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
	cylinder->cy_attrs->diameter = ft_atod(parts[3],
			throw_sys_error, "ft_atod");
	cylinder->cy_attrs->height = ft_atod(parts[4], throw_sys_error, "ft_atod");
	cylinder->print_attrs = print_attrs;
	cylinder->hit = hit;
	return (cylinder);
}
