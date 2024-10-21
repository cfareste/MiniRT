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
	t_coordinates	plane_to_ray;
	float			n_dot_pltoray;
	float			n_dot_rdir;
	float			root;

	n_dot_rdir = dot(&figure->pl_attrs->orientation, &ray->direction);
	if (n_dot_rdir == 0.0)
		return (0);
	plane_to_ray.x = ray->origin.x - figure->position.x;
	plane_to_ray.y = ray->origin.y - figure->position.y;
	plane_to_ray.z = ray->origin.z - figure->position.z;
	n_dot_pltoray = -1 * dot(&figure->pl_attrs->orientation, &plane_to_ray);
	root = n_dot_pltoray / n_dot_rdir;
	if (root <= ray->bounds.min || root >= ray->bounds.max)
		return (0);
	*distance = root;
	return (1);
}

static void	normal(t_figure *figure, t_coordinates *point, \
						t_coordinates *res)
{
	(void) point;
	res->x = figure->pl_attrs->orientation.x;
	res->y = figure->pl_attrs->orientation.y;
	res->z = figure->pl_attrs->orientation.z;
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
	normalize(&plane->pl_attrs->orientation);
	plane->print_attrs = print_attrs;
	plane->hit = hit;
	plane->normal = normal;
	return (plane);
}
