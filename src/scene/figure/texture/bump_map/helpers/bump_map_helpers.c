/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:44:36 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 16:34:02 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bump_map.h"
#include "scene/figure/figure.h"
#include "scene/figure/texture/texel/texel.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/helpers/base_attributes/base_attributes.h"
#include "bump_map_helpers.h"
#include "libft.h"
#include <math.h>

static void	remove_point_texture_offset(t_point *point,
	t_base_point_context *ctx, t_base_attrs *attrs, t_vector *texture_dims)
{
	if (point->x < 0.0)
		ctx->point_arc = -ctx->point_arc + texture_dims->x
			+ (texture_dims->x * (int)(ctx->point_arc / texture_dims->x));
	if (ctx->point_arc >= texture_dims->x)
		ctx->point_arc = ctx->point_arc
			- (texture_dims->x * (int)(ctx->point_arc / texture_dims->x));
	if (attrs->base_distance < 0.0)
		point->z = (attrs->base_distance - ctx->point_base_height)
			+ texture_dims->y
			+ (texture_dims->y * (int)((fabs(attrs->base_distance)
						+ ctx->point_base_height) / texture_dims->y));
	if (attrs->base_distance >= 0.0
		&& attrs->base_distance < texture_dims->y)
		point->z = attrs->base_distance + ctx->point_base_height;
	if (attrs->base_distance >= 0.0
		&& attrs->base_distance + ctx->point_base_height >= texture_dims->y)
		point->z = (attrs->base_distance + ctx->point_base_height)
			- (texture_dims->y * (int)((attrs->base_distance
						+ ctx->point_base_height) / texture_dims->y));
}

static void	set_base_point_attrs(t_point *point,
	t_base_point_context *point_ctx, float radius)
{
	t_vector	base_to_point;

	base_to_point = *point;
	base_to_point.z = 0.0;
	point_ctx->point_radius = sqrt(dot(&base_to_point, &base_to_point));
	normalize(&base_to_point);
	base_to_point.y = ft_fclamp(base_to_point.y, -1.0, 1.0);
	point_ctx->point_arc = acos(base_to_point.y) * point_ctx->point_radius;
	point_ctx->point_base_height = radius - point_ctx->point_radius;
}

void	get_base_bump_normal(t_figure *figure, t_point *point,
	t_base_attrs *base_attrs, t_vector *res)
{
	t_base_point_context	point_ctx;
	t_texture				*texture;
	t_vector				texture_dims;
	uint8_t					*pixel;
	t_texel					texel;

	texture = figure->bump_map.texture;
	set_base_point_attrs(point, &point_ctx, base_attrs->radius);
	texture_dims.x = figure->bump_map.width_dim
		* (point_ctx.point_radius / base_attrs->radius);
	texture_dims.y = figure->bump_map.width_dim
		* (texture->mlx->height / (float) texture->mlx->width);
	remove_point_texture_offset(point, &point_ctx, base_attrs, &texture_dims);
	texel.x = point_ctx.point_arc * (texture->mlx->width / texture_dims.x);
	texel.y = point->z * (texture->mlx->height / texture_dims.y);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	get_pixel_normal(pixel, figure->bump_map.format, res);
	if (base_attrs->base_distance >= 0.0)
		return ;
	rotate_by_axis(UP, M_PI, res);
}

void	get_pixel_normal(uint8_t *pixel, t_bump_map_format format,
	t_vector *res)
{
	t_color	pixel_color;

	pixel_color.red = *pixel / (float) 255;
	pixel_color.green = *(pixel + 1) / (float) 255;
	pixel_color.blue = *(pixel + 2) / (float) 255;
	res->x = (pixel_color.red / 0.5) - 1;
	res->y = (pixel_color.green / 0.5) - 1;
	if (format == DIRECTX)
		res->y *= -1;
	res->z = (pixel_color.blue / 0.5) - 1;
}

void	rotate_bump_to_point_position(t_vector *point_normal, t_vector *res)
{
	t_vector	texture_normal;

	get_axis(&texture_normal, BACK);
	rotate_by_ideal(&texture_normal, point_normal, res);
}
