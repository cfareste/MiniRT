#include "libft.h"
#include "utils/utils.h"
#include "render/scene/figure/figure.h"

static void	print_attrs(void *param)
{
	t_cone_attrs	*attrs;

	attrs = (t_cone_attrs *) param;
	printf("%f, %f, %f | %f | %f ",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_coordinates	cone_to_ray;
	float			n_dot_pltoray;
	float			n_dot_rdir;
	float			root;

	n_dot_rdir = dot(&figure->co_attrs->orientation, &ray->direction);
	if (n_dot_rdir == 0.0)
		return (0);
	cone_to_ray.x = ray->origin.x - figure->position.x;
	cone_to_ray.y = ray->origin.y - figure->position.y;
	cone_to_ray.z = ray->origin.z - figure->position.z;
	n_dot_pltoray = -1 * dot(&figure->co_attrs->orientation, &cone_to_ray);
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
	res->x = figure->co_attrs->orientation.x;
	res->y = figure->co_attrs->orientation.y;
	res->z = figure->co_attrs->orientation.z;
}

t_figure	*new_cone(char **parts)
{
	t_figure	*cone;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing some cone parameter");
	cone = new_figure(parts[0], parts[1], parts[5]);
	cone->co_attrs = ft_calloc(1, sizeof(t_cone_attrs));
	if (!cone->co_attrs)
		throw_sys_error("trying to allocate cone attributes");
	cone->print_attrs = print_attrs;
	cone->hit = hit;
	cone->normal = normal;
	set_coordinates(parts[2], &cone->co_attrs->orientation);
	cone->co_attrs->radius = ft_atod(parts[3], throw_sys_error,
			"allocating ft_atod in cone radius") / 2.0;
	cone->co_attrs->height = ft_atod(parts[4], throw_sys_error,
			"allocating ft_atod in cone height");
	normalize(&cone->co_attrs->orientation);
	return (cone);
}
