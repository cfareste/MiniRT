#include "figure.h"
#include "libft.h"
#include "utils.h"
#include "math.h"
#include "quadratic.h"

static void	print_attrs(void *param)
{
	t_sphere_attrs	*attrs;

	attrs = (t_sphere_attrs *) param;
	printf("%f", attrs->diameter);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_coordinates		ray_to_sphere;
	t_quadratic_params	params;
	float				radius;
	float				square_root;

	ray_to_sphere.x = figure->position.x - ray->origin.x;
	ray_to_sphere.y = figure->position.y - ray->origin.y;
	ray_to_sphere.z = figure->position.z - ray->origin.z;
	radius = figure->sp_attrs->diameter / 2.0;
	params.a = dot(&ray->direction, &ray->direction);
	params.b = -2.0 * dot(&ray->direction, &ray_to_sphere);
	params.c = dot(&ray_to_sphere, &ray_to_sphere) - (radius * radius);
	params.discriminant = (params.b * params.b) - (4.0 * params.a * params.c);
	if (params.discriminant < 0.0)
		return (0);
	square_root = sqrt(params.discriminant);
	params.root = (-params.b - square_root) / (2.0 * params.a);
	if (params.root <= ray->bounds.min || params.root >= ray->bounds.max)
	{
		params.root = (-params.b + square_root) / (2.0 * params.a);
		if (params.root <= ray->bounds.min || params.root >= ray->bounds.max)
			return (0);
	}
	*distance = params.root;
	return (1);
}

static void	normal(t_figure *figure, t_coordinates *point, t_coordinates *res)
{
	res->x = point->x - figure->position.x;
	res->y = point->y - figure->position.y;
	res->z = point->z - figure->position.z;
	normalize(res);
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
	sphere->normal = normal;
	return (sphere);
}
