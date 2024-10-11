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

static void	hit(void)
{
}

t_figure	*new_plane(char **pieces)
{
	t_figure	*plane;

	if (!pieces[1] || !pieces[2] || !pieces[3])
		throw_error("Missing some plane parameter");
	plane = new_figure(pieces[0], pieces[1], pieces[3]);
	plane->pl_attrs = ft_calloc(1, sizeof(t_plane_attrs));
	if (!plane->pl_attrs)
		throw_sys_error("trying to allocate plane attributes");
	set_coordinates(pieces[2], &plane->pl_attrs->orientation);
	plane->print_attrs = print_attrs;
	plane->hit = hit;
	return (plane);
}
