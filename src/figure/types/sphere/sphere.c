#include "figure.h"
#include "libft.h"
#include "utils.h"

static void	print_attrs(void *param)
{
	t_sphere_attrs	*attrs;

	attrs = (t_sphere_attrs *) param;
	printf("%f", attrs->diameter);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	(void) figure;
	(void) ray;
	(void) distance;
	return (0);
}

t_figure	*new_sphere(char **parts)
{
	t_figure	*sphere;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing some sphere parameter");
	sphere = new_figure(parts[0], parts[1], parts[3]);
	sphere->sp_attrs = ft_calloc(1, sizeof(t_sphere_attrs));
	if (!sphere->sp_attrs)
		throw_sys_error("trying to allocate sphere attributes");
	sphere->sp_attrs->diameter = ft_atod(parts[2], throw_sys_error, "ft_atod");
	sphere->print_attrs = print_attrs;
	sphere->hit = hit;
	return (sphere);
}
