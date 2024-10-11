#include "figure.h"
#include "libft.h"
#include "utils.h"

static void	print_attrs(void *param)
{
	t_sphere_attrs	*attrs;

	attrs = (t_sphere_attrs *) param;
	printf("%f", attrs->diameter);
}

static void	hit(void)
{
}

t_figure	*new_sphere(char **pieces)
{
	t_figure	*sphere;

	if (!pieces[1] || !pieces[2] || !pieces[3])
		throw_error("Missing some sphere parameter");
	sphere = new_figure(pieces[0], pieces[1], pieces[3]);
	sphere->sp_attrs = ft_calloc(1, sizeof(t_sphere_attrs));
	if (!sphere->sp_attrs)
		throw_sys_error("trying to allocate sphere attributes");
	sphere->sp_attrs->diameter = ft_atod(pieces[2]);
	sphere->print_attrs = print_attrs;
	sphere->hit = hit;
	return (sphere);
}
