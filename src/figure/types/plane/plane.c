#include "libft.h"
#include "utils.h"
#include "figure.h"

static void	print_attrs(void *param)
{
	t_plane_attrs	*attrs;

	attrs = (t_plane_attrs *) param;
	printf("%f, %f, %f ",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	(void) figure;
	(void) ray;
	(void) distance;
	return (0);
}

t_figure	*new_plane(char **parts)
{
	t_figure	*plane;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing some plane parameter");
	plane = new_figure(parts[0], parts[1], parts[3]);
	plane->pl_attrs = ft_calloc(1, sizeof(t_plane_attrs));
	if (!plane->pl_attrs)
		throw_sys_error("trying to allocate plane attributes");
	set_coordinates(parts[2], &plane->pl_attrs->orientation);
	plane->print_attrs = print_attrs;
	plane->hit = hit;
	return (plane);
}
