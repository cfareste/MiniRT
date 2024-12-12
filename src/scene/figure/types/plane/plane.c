/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 15:38:57 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../parser/figure_parser.h"
#include "scene/figure/figure.h"
#include "render/utils/vector/vector.h"
#include "scene/figure/types/plane/pattern/plane_pattern.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/types/plane/texture/bump_map_plane.h"
#include "scene/figure/events/figure_events.h"
#include "scene/figure/types/plane/helpers/plane_helpers.h"

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
	t_point		rotated_point;
	float		angle;

	if (!figure->bump_map.texture)
	{
		*res = figure->pl_attrs->orientation;
		return ;
	}
	get_vector(point, &figure->position, &rotated_point);
	angle = rotate_reference_system(&figure->pl_attrs->orientation, NULL,
			&rotated_point);
	get_plane_bump_normal(figure, &rotated_point, res);
	rotate_by_angle(&figure->pl_attrs->orientation, -angle, res);
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	t_point	rotated_point;

	get_vector(point, &figure->position, &rotated_point);
	rotate_reference_system(&figure->pl_attrs->orientation, NULL,
		&rotated_point);
	get_plane_pattern(figure, &rotated_point, res);
}

void	set_plane(t_figure *plane, t_point *position, t_plane_attrs *attrs)
{
	plane->pl_attrs = attrs;
	plane->position = *position;
	plane->hit = hit;
	plane->normal = normal;
	plane->rotate = rotate_plane;
	plane->get_color_pattern = get_color;
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
	plane->rotate = rotate_plane;
	plane->get_color_pattern = get_color;
	return (plane);
}
