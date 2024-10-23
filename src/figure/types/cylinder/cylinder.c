#include "figure.h"
#include "libft.h"
#include "utils.h"
#include "math.h"
#include "quadratic.h"
#include "coordinates.h"

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->diameter, attrs->height);
}

void	print_vector(char *name, t_coordinates *vec)
{
	printf("%s: (%.10f, %.10f, %.10f)\n", name, vec->x, vec->y, vec->z);
}

void	rotate_vector(t_coordinates *vec, t_coordinates *axis, float angle,
	t_coordinates *rotated)
{
	t_coordinates	aux;
	float			dot_product;
	float			cosine;
	float			sine;

	cross(axis, vec, &aux);
	cosine = cos(angle);
	sine = sin(angle);
	dot_product = dot(vec, axis);
	rotated->x = (vec->x * cosine) + (aux.x * sine) + (dot_product * axis->x * (1 - cosine));
	rotated->y = (vec->y * cosine) + (aux.y * sine) + (dot_product * axis->y * (1 - cosine));
	rotated->z = (vec->z * cosine) + (aux.z * sine) + (dot_product * axis->z * (1 - cosine));
}

void	rotate_reference_system(t_coordinates *vec, t_coordinates *point,
	t_coordinates *cy_center, t_coordinates *normal)
{
	t_coordinates	ideal;
	t_coordinates	axis;
	float			angle;

	get_axis(&ideal, BACK);
	cross(normal, &ideal, &axis);
	normalize(&axis);
	angle = acos(dot(normal, &ideal));
	rotate_vector(vec, &axis, angle, vec);
	rotate_vector(point, &axis, angle, point);
	rotate_vector(cy_center, &axis, angle, cy_center);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_coordinates	ray_vec;
	t_coordinates	ray_origin;
	t_coordinates	cy_center;

	ray_vec = ray->direction;
	ray_origin = ray->origin;
	cy_center = figure->position;
	rotate_reference_system(&ray_vec, &ray_origin, &cy_center, &figure->cy_attrs->orientation);


	// HIT FUNCTION
	t_coordinates		ray_to_cylinder;
	t_quadratic_params	params;
	float				radius;
	float				square_root;

	ray_to_cylinder.x = cy_center.x - ray_origin.x;
	ray_to_cylinder.y = cy_center.y - ray_origin.y;
	ray_to_cylinder.z = 0;
	radius = figure->cy_attrs->diameter / 2.0;
	params.a = (ray_vec.x * ray_vec.x) + (ray_vec.y * ray_vec.y);
	params.b = -2.0 * ((ray_vec.x * ray_to_cylinder.x) + (ray_vec.y * ray_to_cylinder.y));
	params.c = (ray_to_cylinder.x * ray_to_cylinder.x) + (ray_to_cylinder.y * ray_to_cylinder.y) - (radius * radius);
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

static void	normal(t_figure *figure, t_coordinates *point,
	t_coordinates *res)
{
	t_coordinates	center_to_point;
	float			diagonal;
	float			radius;
	float			total_height;
	t_coordinates	center_offset;

	center_to_point.x = point->x - figure->position.x;
	center_to_point.y = point->y - figure->position.y;
	center_to_point.z = point->z - figure->position.z;
	diagonal = dot(&center_to_point, &center_to_point);
	radius = figure->cy_attrs->diameter / 2.0;
	total_height = sqrtf(diagonal - (radius * radius));
	if (dot(&center_to_point, &figure->cy_attrs->orientation) < 0.0)
		total_height *= -1;
	center_offset.x = figure->position.x + total_height * figure->cy_attrs->orientation.x;
	center_offset.y = figure->position.y + total_height * figure->cy_attrs->orientation.y;
	center_offset.z = figure->position.z + total_height * figure->cy_attrs->orientation.z;
	res->x = point->x - center_offset.x;
	res->y = point->y - center_offset.y;
	res->z = point->z - center_offset.z;
	normalize(res);
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
	normalize(&cylinder->cy_attrs->orientation);
	cylinder->print_attrs = print_attrs;
	cylinder->hit = hit;
	cylinder->normal = normal;
	return (cylinder);
}
