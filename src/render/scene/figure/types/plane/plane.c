/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 09:14:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "../../parser/figure_parser.h"
#include "render/scene/figure/figure.h"
#include "render/utils/vector/vector.h"

static void	print_attrs(void *param)
{
	t_plane_attrs	*attrs;

	attrs = (t_plane_attrs *) param;
	printf("%f, %f, %f ",
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_vector	plane_to_ray;
	float		n_dot_pltoray;
	float		n_dot_rdir;
	float		root;

	n_dot_rdir = dot(&figure->pl_attrs->orientation, &ray->direction);
	if (n_dot_rdir == 0.0)
		return (0);
	get_vector(&ray->origin, &figure->position, &plane_to_ray);
	n_dot_pltoray = -1 * dot(&figure->pl_attrs->orientation, &plane_to_ray);
	root = n_dot_pltoray / n_dot_rdir;
	if (root <= ray->bounds.min || root >= ray->bounds.max)
		return (0);
	*distance = root;
	return (1);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	(void) point;
	*res = figure->pl_attrs->orientation;
}

void	set_plane(t_figure *plane, t_point *position, t_plane_attrs *attrs)
{
	plane->print_attrs = print_attrs;
	plane->normal = normal;
	plane->hit = hit;
	plane->pl_attrs = attrs;
	plane->position = *position;
}
