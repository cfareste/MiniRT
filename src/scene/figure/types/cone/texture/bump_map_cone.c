/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:24:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/13 21:56:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/texture/texel/texel.h"
#include "scene/figure/types/cone/helpers/cone_helpers.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers.h"
#include "libft.h"
#include <math.h>

static void	rotate_texture_normal(t_point *point, t_figure *cone, t_vector *res)
{
	t_vector	point_normal;
	t_vector	projected;
	t_vector	axis;
	float		angle;

	projected = *point;
	projected.z = 0;
	normalize(&projected);
	cross(point, &projected, &axis);
	normalize(&axis);
	angle = sin(cone->co_attrs->radius
			/ hypot(cone->co_attrs->radius, cone->co_attrs->height));
	rotate_vector(&projected, &axis, angle, &point_normal);
	normalize(&point_normal);
	rotate_bump_to_point_position(&point_normal, res);
}

static void	remove_point_texture_offset(t_point *point, float *arc,
	t_vector *texture_dims)
{
	if (point->x < 0.0)
		*arc = -*arc + texture_dims->x
			+ (texture_dims->x * (int)(*arc / texture_dims->x));
	if (point->z < 0.0)
		point->z = point->z + texture_dims->y
			+ (texture_dims->y * (int)(fabs(point->z) / texture_dims->y));
	if (*arc >= texture_dims->x)
		*arc = *arc
			- (texture_dims->x * (int)(*arc / texture_dims->x));
	if (point->z >= texture_dims->y)
		point->z = point->z
			- (texture_dims->y * (int)(point->z / texture_dims->y));
}

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
	
	float		point_radius;

	point_radius = point->z
		* (figure->co_attrs->radius / figure->co_attrs->height);
	texture_dims.x = figure->bump_map.width_dim
		* (point_radius / figure->co_attrs->radius);
	texture_dims.y = figure->bump_map.width_dim
		* (texture->mlx->height / (float) texture->mlx->width);
	angle = get_point_angle(point);
	arc = angle * point_radius;
	remove_point_texture_offset(point, &arc, &texture_dims);
	texel.x = arc * (texture->mlx->width / texture_dims.x);
	texel.y = point->z * (texture->mlx->height / texture_dims.y);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	get_pixel_normal(pixel, figure->bump_map.format, res);
	rotate_texture_normal(point, figure, res);
}

void	get_cone_bump_normal(t_figure *figure, t_point *point, int is_base,
	t_vector *res)
{
	t_point		translated_center;
	t_point		rotated_point;
	float		angle;

	translate_point(point, &figure->co_attrs->orientation,
		-figure->co_attrs->height / 2.0, &rotated_point);
	translate_point(&figure->position, &figure->co_attrs->orientation,
		-figure->co_attrs->height / 2.0, &translated_center);
	get_vector(&rotated_point, &translated_center, &rotated_point);
	angle = rotate_reference_system(&figure->co_attrs->orientation, NULL,
			&rotated_point);
	if (!is_base)
		get_body_texture_normal(figure, &rotated_point,
			figure->bump_map.texture, res);
	else if (is_base == 1)
		*res = figure->co_attrs->orientation;
	rotate_by_angle(&figure->co_attrs->orientation, -angle, res);
}