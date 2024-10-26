#include "figure.h"
#include "libft.h"
#include "utils.h"
#include "math.h"
#include "float.h"
#include "quadratic.h"
#include "coordinates.h"

typedef struct s_reference_system
{
	t_ray			ray;
	t_coordinates	center;
}	t_reference_system;

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
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
	if (axis.x == 0.0 && axis.y == 0.0 && axis.z == 0.0)
		return ;
	normalize(&axis);
	angle = acos(dot(normal, &ideal));
	rotate_vector(vec, &axis, angle, vec);
	rotate_vector(point, &axis, angle, point);
	rotate_vector(cy_center, &axis, angle, cy_center);
}

float	get_height(t_coordinates *point, t_coordinates *center, float base)
{
	t_coordinates	center_to_point;
	float			point_height;
	float			hypotenuse;

	center_to_point.x = point->x - center->x;
	center_to_point.y = point->y - center->y;
	center_to_point.z = point->z - center->z;
	hypotenuse = dot(&center_to_point, &center_to_point);
	point_height = sqrt(hypotenuse - base * base);
	return (point_height);
}

int	belongs_to_base(t_coordinates *point, t_coordinates *center, t_coordinates *normal, float height)
{
	t_coordinates	top_to_point;
	t_coordinates	bottom_to_point;
	float			dot_top;
	float			dot_bottom;

	top_to_point.x = point->x - (center->x + (height / 2.0) * normal->x);
	top_to_point.y = point->y - (center->y + (height / 2.0) * normal->y);
	top_to_point.z = point->z - (center->z + (height / 2.0) * normal->z);
	normalize(&top_to_point);
	bottom_to_point.x = point->x - (center->x - (height / 2.0) * normal->x);
	bottom_to_point.y = point->y - (center->y - (height / 2.0) * normal->y);
	bottom_to_point.z = point->z - (center->z - (height / 2.0) * normal->z);
	normalize(&bottom_to_point);
	dot_top = dot(normal, &top_to_point);
	dot_bottom = dot(normal, &bottom_to_point);
	if (fabs(dot_top) > 0.0001 && fabs(dot_bottom) > 0.0001)
		return (0);
	if (fabs(dot_top) < 0.0001)
		return (1);
	else
		return (-1);
}

int	hit_base(t_reference_system *refsys, float base_center_distance, float radius, float *distance)
{
	t_figure		plane;
	t_plane_attrs	pl_attrs;
	t_coordinates	base_center;
	t_coordinates	hit_to_base_center;
	float			base_distance;

	base_distance = FLT_MAX;
	ft_bzero(&pl_attrs, sizeof(t_plane_attrs));
	pl_attrs.orientation.z = 1.0f;
	ft_bzero(&base_center, sizeof(t_coordinates));
	base_center.z = refsys->center.z + base_center_distance;
	set_plane(&plane, &base_center, &pl_attrs);
	if (!plane.hit(&plane, &refsys->ray, &base_distance))
		return (0);
	hit_to_base_center.x = refsys->ray.origin.x + (refsys->ray.direction.x * base_distance) - base_center.x;
	hit_to_base_center.y = refsys->ray.origin.y + (refsys->ray.direction.y * base_distance) - base_center.y;
	hit_to_base_center.z = refsys->ray.origin.z + (refsys->ray.direction.z * base_distance) - base_center.z;
	if (base_distance <= refsys->ray.bounds.min || base_distance >= refsys->ray.bounds.max
		|| sqrt(dot(&hit_to_base_center, &hit_to_base_center)) > radius)
		return (0);
	if (base_distance > *distance)
		return (0);
	*distance = base_distance;
	return (1);
}

int	hit_body(t_reference_system *refsys, t_figure *cylinder, t_ray *ray, float *distance)
{
	t_coordinates		ray_to_cylinder;
	t_quadratic_params	params;
	t_coordinates		point;
	float				point_height;

	ray_to_cylinder.x = refsys->center.x - refsys->ray.origin.x;
	ray_to_cylinder.y = refsys->center.y - refsys->ray.origin.y;
	ray_to_cylinder.z = 0;
	params.a = (refsys->ray.direction.x * refsys->ray.direction.x) + (refsys->ray.direction.y * refsys->ray.direction.y);
	params.b = -2.0 * ((refsys->ray.direction.x * ray_to_cylinder.x) + (refsys->ray.direction.y * ray_to_cylinder.y));
	params.c = (ray_to_cylinder.x * ray_to_cylinder.x) + (ray_to_cylinder.y * ray_to_cylinder.y) - (pow(cylinder->cy_attrs->radius, 2));
	params.discriminant = (params.b * params.b) - (4.0 * params.a * params.c);
	if (params.discriminant < 0.0)
		return (0);
	params.square_root = sqrt(params.discriminant);
	params.roots.close = (-params.b - params.square_root) / (2.0 * params.a);
	point.x = refsys->ray.origin.x + params.roots.close * refsys->ray.direction.x;
	point.y = refsys->ray.origin.y + params.roots.close * refsys->ray.direction.y;
	point.z = refsys->ray.origin.z + params.roots.close * refsys->ray.direction.z;
	point_height = get_height(&point, &refsys->center, cylinder->cy_attrs->radius);
	if (params.roots.close <= ray->bounds.min || params.roots.close >= ray->bounds.max
		|| point_height > cylinder->cy_attrs->height / 2.0)
	{
		params.roots.far = (-params.b + params.square_root) / (2.0 * params.a);
		point.x = refsys->ray.origin.x + params.roots.far * refsys->ray.direction.x;
		point.y = refsys->ray.origin.y + params.roots.far * refsys->ray.direction.y;
		point.z = refsys->ray.origin.z + params.roots.far * refsys->ray.direction.z;
		point_height = get_height(&point, &refsys->center, cylinder->cy_attrs->radius);
		if (params.roots.far <= ray->bounds.min || params.roots.far >= ray->bounds.max
			|| point_height > cylinder->cy_attrs->height / 2.0)
			return (0);
		params.roots.close = params.roots.far;
	}
	if (*distance < params.roots.close)
		return (0);
	*distance = params.roots.close;
	return (1);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_reference_system	refsys;
	int					hitted;

	refsys.ray.bounds.min = ray->bounds.min;
	refsys.ray.bounds.max = ray->bounds.max;
	refsys.ray.origin.x = ray->origin.x - figure->position.x;
	refsys.ray.origin.y = ray->origin.y - figure->position.y;
	refsys.ray.origin.z = ray->origin.z - figure->position.z;
	refsys.ray.direction = ray->direction;
	ft_bzero(&refsys.center, sizeof(t_coordinates));
	rotate_reference_system(&refsys.ray.direction, &refsys.ray.origin, &refsys.center, &figure->cy_attrs->orientation);
	hitted = hit_base(&refsys, figure->cy_attrs->height / 2.0, figure->cy_attrs->radius, distance);
	hitted |= hit_body(&refsys, figure, ray, distance);
	hitted |= hit_base(&refsys, -figure->cy_attrs->height / 2.0, figure->cy_attrs->radius, distance);
	return (hitted);
}

static void	normal(t_figure *figure, t_coordinates *point,
	t_coordinates *res)
{
	int				is_base;
	float			point_height;
	t_coordinates	center_offset;
	t_coordinates	center_to_point;

	is_base = belongs_to_base(point, &figure->position, &figure->cy_attrs->orientation, figure->cy_attrs->height);
	if (is_base == 1)
		*res = figure->cy_attrs->orientation;
	else if (is_base == -1)
	{
		res->x = -figure->cy_attrs->orientation.x;
		res->y = -figure->cy_attrs->orientation.y;
		res->z = -figure->cy_attrs->orientation.z;
	}
	else
	{
		center_to_point.x = point->x - figure->position.x;
		center_to_point.y = point->y - figure->position.y;
		center_to_point.z = point->z - figure->position.z;
		point_height = get_height(point, &figure->position,
			figure->cy_attrs->radius);
		if (dot(&center_to_point, &figure->cy_attrs->orientation) < 0.0)
			point_height *= -1;
		center_offset.x = figure->position.x
			+ point_height * figure->cy_attrs->orientation.x;
		center_offset.y = figure->position.y
			+ point_height * figure->cy_attrs->orientation.y;
		center_offset.z = figure->position.z
			+ point_height * figure->cy_attrs->orientation.z;
		res->x = point->x - center_offset.x;
		res->y = point->y - center_offset.y;
		res->z = point->z - center_offset.z;
		normalize(res);
	}
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
	cylinder->cy_attrs->radius = ft_atod(parts[3],
			throw_sys_error, "ft_atod") / 2.0f;
	cylinder->cy_attrs->height = ft_atod(parts[4], throw_sys_error, "ft_atod");
	normalize(&cylinder->cy_attrs->orientation);
	cylinder->print_attrs = print_attrs;
	cylinder->hit = hit;
	cylinder->normal = normal;
	return (cylinder);
}
