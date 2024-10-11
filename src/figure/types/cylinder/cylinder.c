#include "figure.h"
#include "libft.h"
#include "utils.h"
#include "coordinates.h"

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->diameter, attrs->height);
}

static void	hit(void)
{
}

t_figure	*new_cylinder(char **pieces)
{
	t_figure	*cylinder;

	if (!pieces[1] || !pieces[2] || !pieces[3] || !pieces[4] || !pieces[5])
		throw_error("Missing some cylinder parameter");
	cylinder = new_figure(pieces[0], pieces[1], pieces[5]);
	cylinder->cy_attrs = ft_calloc(1, sizeof(t_cylinder_attrs));
	if (!cylinder->cy_attrs)
		throw_sys_error("trying to allocate cylinder attributes");
	set_coordinates(pieces[2], &cylinder->cy_attrs->orientation);
	cylinder->cy_attrs->diameter = ft_atod(pieces[3]);
	cylinder->cy_attrs->height = ft_atod(pieces[4]);
	cylinder->print_attrs = print_attrs;
	cylinder->hit = hit;
	return (cylinder);
}
