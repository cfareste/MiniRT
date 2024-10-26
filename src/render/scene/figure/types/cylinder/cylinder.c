#include "libft.h"
#include "float.h"
#include "utils/utils.h"
#include "render/utils/point/point.h"
#include "render/scene/figure/figure.h"
#include "render/utils/vector/vector.h"
#include "render/utils/quadratic/quadratic.h"
#include "render/utils/coordinates/coordinates.h"
#include <math.h>

static void	print_attrs(void *param)
{
	t_cylinder_attrs	*attrs;

	attrs = (t_cylinder_attrs *) param;
	printf("%f, %f, %f | %f | %f",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z,
		attrs->radius, attrs->height);
}

void	print_vector(char *name, t_vector *vec)
{
	printf("%s: (%.10f, %.10f, %.10f)\n", name, vec->x, vec->y, vec->z);
}

void	rotate_vector(t_vector *vec, t_vector *axis, float angle,
	t_vector *rotated)
{
	t_vector	aux;
	float		dot_product;
	float		cosine;
	float		sine;

	cross(axis, vec, &aux);
	cosine = cos(angle);
	sine = sin(angle);
	dot_product = dot(vec, axis);
	rotated->x = (vec->x * cosine) + (aux.x * sine)
		+ (dot_product * axis->x * (1 - cosine));
	rotated->y = (vec->y * cosine) + (aux.y * sine)
		+ (dot_product * axis->y * (1 - cosine));
	rotated->z = (vec->z * cosine) + (aux.z * sine)
		+ (dot_product * axis->z * (1 - cosine));
}

void	rotate_reference_system(t_vector *vec, t_point *point,
	t_point *cy_center, t_vector *normal)
{
	t_vector	ideal;
	t_vector	axis;
	float		angle;

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

float	get_height(t_point *point, t_point *center, float base)
{
	t_vector	center_to_point;
	float		point_height;
	float		hypotenuse;

	get_vector(point, center, &center_to_point);
	hypotenuse = dot(&center_to_point, &center_to_point);
	point_height = sqrt(hypotenuse - base * base);
	return (point_height);
}

int	belongs_to_base(t_point *point, t_point *center, t_vector *normal,
	float height)
{
	t_vector	top_to_point;
	t_vector	bottom_to_point;
	float		dot_top;
	float		dot_bottom;

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
	t_point			base_center;
	t_vector		hit_to_base_center;
	float			base_distance;

	base_distance = FLT_MAX;
	ft_bzero(&pl_attrs, sizeof(t_plane_attrs));
	pl_attrs.orientation.z = 1.0f;
	ft_bzero(&base_center, sizeof(t_point));
	base_center.z = refsys->center.z + base_center_distance;
	set_plane(&plane, &base_center, &pl_attrs);
	if (!plane.hit(&plane, &refsys->ray, &base_distance))
		return (0);
	translate_point(&refsys->ray.origin, &refsys->ray.direction, base_distance,
		&hit_to_base_center);
	get_vector(&hit_to_base_center, &base_center, &hit_to_base_center);
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
	t_vector			ray_to_cylinder;
	t_quadratic_params	params;
	t_point				point;
	float				point_height;

	get_vector(&refsys->center, &refsys->ray.origin, &ray_to_cylinder);
	ray_to_cylinder.z = 0;
	params.a = (refsys->ray.direction.x * refsys->ray.direction.x) + (refsys->ray.direction.y * refsys->ray.direction.y);
	params.b = -2.0 * ((refsys->ray.direction.x * ray_to_cylinder.x) + (refsys->ray.direction.y * ray_to_cylinder.y));
	params.c = (ray_to_cylinder.x * ray_to_cylinder.x) + (ray_to_cylinder.y * ray_to_cylinder.y) - (pow(cylinder->cy_attrs->radius, 2));
	params.discriminant = (params.b * params.b) - (4.0 * params.a * params.c);
	if (params.discriminant < 0.0)
		return (0);
	params.square_root = sqrt(params.discriminant);
	params.roots.close = (-params.b - params.square_root) / (2.0 * params.a);
	translate_point(&refsys->ray.origin, &refsys->ray.direction,
		params.roots.close, &point);
	point_height = get_height(&point, &refsys->center, cylinder->cy_attrs->radius);
	if (params.roots.close <= ray->bounds.min || params.roots.close >= ray->bounds.max
		|| point_height > cylinder->cy_attrs->height / 2.0)
	{
		params.roots.far = (-params.b + params.square_root) / (2.0 * params.a);
		translate_point(&refsys->ray.origin, &refsys->ray.direction,
			params.roots.far, &point);
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
	get_vector(&ray->origin, &figure->position, &refsys.ray.origin);
	refsys.ray.direction = ray->direction;
	ft_bzero(&refsys.center, sizeof(t_point));
	rotate_reference_system(&refsys.ray.direction, &refsys.ray.origin, &refsys.center, &figure->cy_attrs->orientation);
	hitted = hit_base(&refsys, figure->cy_attrs->height / 2.0, figure->cy_attrs->radius, distance);
	hitted |= hit_body(&refsys, figure, ray, distance);
	hitted |= hit_base(&refsys, -figure->cy_attrs->height / 2.0, figure->cy_attrs->radius, distance);
	return (hitted);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	int			is_base;
	float		point_height;
	t_point		center_offset;
	t_vector	center_to_point;

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
		get_vector(point, &figure->position, &center_to_point);
		point_height = get_height(point, &figure->position,
			figure->cy_attrs->radius);
		if (dot(&center_to_point, &figure->cy_attrs->orientation) < 0.0)
			point_height *= -1;
		translate_point(&figure->position, &figure->cy_attrs->orientation,
			point_height, &center_offset);
		get_vector(point, &center_offset, res);
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
