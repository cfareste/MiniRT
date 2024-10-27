/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:42 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:54:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "libft.h"
#include "utils/utils.h"
#include "render/scene/figure/figure.h"
#include "render/utils/vector/vector.h"
#include "render/utils/quadratic/quadratic.h"

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

t_figure	*new_sphere(char **parts)
{
	t_figure	*sphere;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing some sphere parameter");
	sphere = new_figure(parts[0], parts[1], parts[3]);
	sphere->sp_attrs = ft_calloc(1, sizeof(t_sphere_attrs));
	if (!sphere->sp_attrs)
		throw_sys_error("trying to allocate sphere attributes");
	sphere->sp_attrs->radius = ft_atod(parts[2],
			throw_sys_error, "ft_atod") / 2.0;
	sphere->print_attrs = print_attrs;
	sphere->hit = hit;
	sphere->normal = normal;
	return (sphere);
}
