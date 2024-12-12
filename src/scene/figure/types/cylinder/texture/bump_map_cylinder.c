/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:31:19 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 11:01:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/texture/texel/texel.h"
#include "scene/figure/texture/bump_map/bump_map.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers.h"
#include "libft.h"
#include <math.h>

static void	rotate_texture_normal(t_point *point, t_vector *res)
{
	t_vector	point_normal;

	point_normal = *point;
	point_normal.z = 0;
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

	texture_dims.x = figure->bump_map.width_dim;
	texture_dims.y = figure->bump_map.width_dim
		* (texture->mlx->height / (float) texture->mlx->width);
	angle = get_point_angle(point);
	arc = angle * figure->cy_attrs->radius;
	remove_point_texture_offset(point, &arc, &texture_dims);
	texel.x = arc * (texture->mlx->width / texture_dims.x);
	texel.y = point->z * (texture->mlx->height / texture_dims.y);
	texel.x = ft_clamp(texel.x, 0, texture->mlx->width - 1);
	texel.y = ft_clamp(texel.y, 0, texture->mlx->height - 1);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	get_pixel_normal(pixel, figure->bump_map.format, res);
	rotate_texture_normal(point, res);
}

void	get_cylinder_bump_normal(t_figure *figure, t_point *point, int is_base,
	t_vector *res)
{
	t_vector		ideal;
	t_base_attrs	base_attrs;
	t_point			rotated_point;
	t_vector		cylinder_reverse_normal;
	float			angle;

	base_attrs.radius = figure->cy_attrs->radius;
	base_attrs.base_distance = -figure->cy_attrs->height / 2.0 * is_base;
	get_vector(point, &figure->position, &rotated_point);
	multiply_vector_scalar(&figure->cy_attrs->orientation, -1,
		&cylinder_reverse_normal);
	angle = rotate_reference_system(&cylinder_reverse_normal, NULL,
			&rotated_point);
	if (!is_base)
		get_body_texture_normal(figure, &rotated_point,
			figure->bump_map.texture, res);
	else
		get_base_bump_normal(figure, &rotated_point, &base_attrs, res);
	get_world_axis(&ideal, BACK);
	if (is_base && base_attrs.base_distance == 0.0
		&& dot(&ideal, &figure->cy_attrs->orientation) != -1.0)
		rotate_by_world_axis(UP, M_PI, res);
	rotate_by_angle(&cylinder_reverse_normal, -angle, res);
}
