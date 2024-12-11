/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:49:31 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 14:23:17 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/texture/texel/texel.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers.h"
#include "libft.h"
#include <math.h>

static void	remove_point_texture_offset(t_point *point, t_vector *texture_dims)
{
	if (point->x < 0.0)
		point->x = point->x + texture_dims->x
			+ (texture_dims->x * (int)(fabs(point->x / texture_dims->x)));
	if (point->y > 0.0)
		point->y = point->y - texture_dims->y
			- (texture_dims->y * (int)(point->y / texture_dims->y));
	if (point->x >= texture_dims->x)
		point->x = point->x
			- (texture_dims->x * (int)(point->x / texture_dims->x));
	if (fabs(point->y) >= texture_dims->y)
		point->y = point->y
			+ (texture_dims->y * (int)(fabs(point->y) / texture_dims->y));
}

static void	get_texture_normal(t_figure *figure, t_point *point,
	t_texture *texture, t_vector *res)
{
	t_vector	texture_dims;
	uint8_t		*pixel;
	t_texel		texel;

	texture_dims.x = figure->bump_map.width_dim;
	texture_dims.y = figure->bump_map.width_dim
		* (texture->mlx->height / (float) texture->mlx->width);
	remove_point_texture_offset(point, &texture_dims);
	texel.x = point->x * (texture->mlx->width / texture_dims.x);
	texel.y = fabs(point->y) * (texture->mlx->height / texture_dims.y);
	texel.x = ft_clamp(texel.x, 0, texture->mlx->width - 1);
	texel.y = ft_clamp(texel.y, 0, texture->mlx->height - 1);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	get_pixel_normal(pixel, figure->bump_map.format, res);
}

void	get_plane_bump_normal(t_figure *figure, t_point *point, t_vector *res)
{
	get_texture_normal(figure, point, figure->bump_map.texture, res);
}
