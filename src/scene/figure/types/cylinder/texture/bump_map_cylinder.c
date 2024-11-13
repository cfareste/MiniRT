/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:31:19 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/13 02:45:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/texture/texel/texel.h"
#include "scene/figure/texture/bump_map/bump_map.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers.h"
#include "libft.h"
#include <math.h>

#include <stdio.h>
#include "scene/figure/helpers/figure_helpers.h"

static void	remove_point_texture_offset(t_point *point, float *arc,
	t_vector *texture_dims)
{
	if (point->x < 0.0)
		*arc = -*arc + texture_dims->x
			+ (texture_dims->x * (int)(*arc / texture_dims->x));
	if (point->z > 0.0)
		point->z = point->z - texture_dims->y
			- (texture_dims->y * (int)(point->z / texture_dims->y));
	if (*arc > texture_dims->x)
		*arc = *arc
			- (texture_dims->x * (int)(*arc / texture_dims->x));
	if (fabs(point->z) > texture_dims->y)
		point->z = point->z
			+ (texture_dims->y * (int)(fabs(point->z) / texture_dims->y));
}

// static void	rotate_by_angle_by_axis(float angle, t_pointing axis_direction,
// 	t_vector *res)
// {
// 	t_vector	axis;
// 	get_axis(&axis, axis_direction);
// 	rotate_vector(res, &axis, angle, res);
// }

static float	get_point_angle(t_point *point)
{
	t_vector	center_to_point;
	float		angle;

	center_to_point = *point;
	center_to_point.z = 0;
	normalize(&center_to_point);
	center_to_point.y = ft_fclamp(center_to_point.y, -1.0, 1.0);
	angle = acos(center_to_point.y);
	return (angle);
}

static void	get_body_texture_normal(t_figure *figure, t_point *point,
	t_texture *texture, t_vector *res)
{
	t_vector	texture_dims;
	uint8_t		*pixel;
	t_texel		texel;
	float		angle;
	float		arc;

	texture_dims.x = figure->bump_map.width_dim;
	texture_dims.y = figure->bump_map.width_dim
		* (texture->mlx->height / (float) texture->mlx->width);
	angle = get_point_angle(point);
	arc = angle * figure->cy_attrs->radius;
	remove_point_texture_offset(point, &arc, &texture_dims);
	texel.x = arc * (texture->mlx->width / texture_dims.x);
	texel.y = fabs(point->z) * (texture->mlx->height / texture_dims.y);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	get_pixel_normal(pixel, figure->bump_map.format, res);
	rotate_bump_to_point_position(point, res);
}

// rotate_by_angle_by_axis(M_PI_2, LEFT, res);
// if (point->x > 0.0)
// 	rotate_by_angle_by_axis(angle, FRONT, res);
// else
// 	rotate_by_angle_by_axis(-angle, FRONT, res);

void	get_cylinder_bump_normal(t_figure *figure, t_point *point, int is_base,
	t_vector *res)
{
	t_point		rotated_point;
	float		angle;

	get_vector(point, &figure->position, &rotated_point);
	angle = rotate_reference_system(&figure->cy_attrs->orientation, NULL,
			&rotated_point);
	if (!is_base)
		get_body_texture_normal(figure, &rotated_point,
			figure->bump_map.texture, res);
	else if (is_base == 1)
		*res = figure->cy_attrs->orientation;
	else if (is_base == -1)
		multiply_vector_scalar(&figure->cy_attrs->orientation, -1, res);
	rotate_by_angle(&figure->pl_attrs->orientation, -angle, res);
}
