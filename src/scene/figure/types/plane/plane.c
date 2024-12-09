/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/08 20:18:04 by cfidalgo         ###   ########.fr       */
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

static void	rotate(t_figure *figure, t_point *factor)
{
	handle_figure_rotation(&figure->pl_attrs->orientation, factor);
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
	get_plane_bump_normal(figure, point, res);
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
	plane->print_attrs = NULL;
	plane->normal = normal;
	plane->hit = hit;
	plane->pl_attrs = attrs;
	plane->position = *position;
	plane->get_color_pattern = get_color;
	plane->rotate = rotate;
}
