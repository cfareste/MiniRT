/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:42 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:33:03 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "libft.h"
#include "utils/utils.h"
#include "render/utils/quadratic/quadratic.h"
#include "../../figure.h"

static void	print_attrs(void *param)
{
	t_sphere_attrs	*attrs;

	attrs = (t_sphere_attrs *) param;
	printf("%f", attrs->radius);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_vector			ray_to_sphere;
	t_quadratic_params	params;
	float				root;

	get_vector(&figure->position, &ray->origin, &ray_to_sphere);
	params.a = dot(&ray->direction, &ray->direction);
	params.b = -2.0 * dot(&ray->direction, &ray_to_sphere);
	params.c = dot(&ray_to_sphere, &ray_to_sphere)
		- (pow(figure->sp_attrs->radius, 2));
	params.discriminant = (params.b * params.b) - (4.0 * params.a * params.c);
	if (params.discriminant < 0.0)
		return (0);
	params.square_root = sqrt(params.discriminant);
	root = (-params.b - params.square_root) / (2.0 * params.a);
	if (root <= ray->bounds.min || root >= ray->bounds.max)
	{
		root = (-params.b + params.square_root) / (2.0 * params.a);
		if (root <= ray->bounds.min || root >= ray->bounds.max)
			return (0);
	}
	*distance = root;
	return (1);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	get_vector(point, &figure->position, res);
	normalize(res);
}

t_figure	*new_sphere(t_point *pos, t_color *color, t_sphere_attrs *sp_attrs)
{
	t_figure	*sphere;

	sphere = new_figure(SPHERE_ID, pos, color);
	sphere->sp_attrs = ft_calloc(1, sizeof(t_sphere_attrs));
	if (!sphere->sp_attrs)
		throw_sys_error("trying to allocate sphere attributes");
	sphere->sp_attrs->radius = sp_attrs->radius;
	sphere->hit = hit;
	sphere->normal = normal;
	sphere->print_attrs = print_attrs;
	return (sphere);
}
