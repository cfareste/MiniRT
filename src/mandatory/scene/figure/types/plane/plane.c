/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:30:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "../../figure.h"
#include "render/utils/reference_system/reference_system.h"

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
	plane->pl_attrs = attrs;
	plane->position = *position;
	plane->hit = hit;
	plane->normal = normal;
}

t_figure	*new_plane(t_point *pos, t_color *color, t_plane_attrs *pl_attrs)
{
	t_figure	*plane;

	plane = new_figure(PLANE_ID, pos, color);
	plane->pl_attrs = ft_calloc(1, sizeof(t_plane_attrs));
	if (!plane->pl_attrs)
		throw_sys_error("trying to allocate plane attributes");
	plane->pl_attrs->orientation = pl_attrs->orientation;
	normalize(&plane->pl_attrs->orientation);
	plane->hit = hit;
	plane->normal = normal;
	return (plane);
}
