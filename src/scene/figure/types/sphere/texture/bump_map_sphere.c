/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:31 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/14 18:32:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/texture/texel/texel.h"
#include "scene/figure/types/sphere/helpers/polar_coordinates.h"
#include "scene/figure/texture/bump_map/helpers/bump_map_helpers.h"
#include "libft.h"
#include <math.h>

#include <stdio.h>

static void	remove_point_texture_offset(t_point *point,
	t_polar_coordinates *coords, t_vector *texture_dims)
{
	if (point->x < 0.0)
		coords->latitude = -coords->latitude + texture_dims->x
			+ (texture_dims->x * (int)(coords->latitude / texture_dims->x));
	if (point->y > 0.0)
		coords->longitude = -coords->longitude + texture_dims->y
			+ (texture_dims->y * (int)(coords->longitude / texture_dims->y));
	if (coords->latitude >= texture_dims->x)
		coords->latitude = coords->latitude
			- (texture_dims->x * (int)(coords->latitude / texture_dims->x));
	if (coords->longitude >= texture_dims->y)
		coords->longitude = coords->longitude
			- (texture_dims->y * (int)(coords->longitude / texture_dims->y));
}

static void	rotate_texture_normal(t_point *point, t_vector *res)
{
	t_vector	point_normal;

	point_normal = *point;
	normalize(&point_normal);
	rotate_bump_to_point_position(&point_normal, res);
}

static void	get_polar_coordinates(t_point *point, t_figure *sphere,
	t_polar_coordinates *coords)
{
	float		longitude_angle;
	float		latitude_angle;
	float		projected_radius;
	t_vector	point_normal;
	t_vector	latitude_normal;

	point_normal = *point;
	latitude_normal = *point;
	latitude_normal.y = 0.0;
	normalize(&latitude_normal);
	normalize(&point_normal);
	projected_radius = sqrt(pow(point->x, 2) + pow(point->z, 2));
	longitude_angle = acos(ft_fclamp(dot(&point_normal, &latitude_normal),
				-1.0, 1.0));
	latitude_angle = acos(ft_fclamp(latitude_normal.z, -1.0, 1.0));
	coords->latitude = latitude_angle * projected_radius;
	coords->longitude = longitude_angle * sphere->sp_attrs->radius;
}

static void	get_bump_normal(t_figure *figure, t_point *point,
	t_texture *texture, t_vector *res)
{
	t_polar_coordinates	coords;
	t_vector			texture_dims;
	uint8_t				*pixel;
	t_texel				texel;
	float				point_radius;

	get_polar_coordinates(point, figure, &coords);
	point_radius = sqrt(pow(point->x, 2) + pow(point->z, 2));
	texture_dims.x = figure->bump_map.width_dim
		* (point_radius / figure->sp_attrs->radius);
	texture_dims.y = figure->bump_map.width_dim
		* (texture->mlx->height / (float) texture->mlx->width);
	remove_point_texture_offset(point, &coords, &texture_dims);
	texel.x = coords.latitude * (texture->mlx->width / texture_dims.x);
	texel.y = coords.longitude * (texture->mlx->height / texture_dims.y);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	get_pixel_normal(pixel, figure->bump_map.format, res);
	rotate_texture_normal(point, res);
}

void	get_sphere_bump_normal(t_figure *figure, t_point *point, t_vector *res)
{
	t_point	translated_point;

	get_vector(point, &figure->position, &translated_point);
	get_bump_normal(figure, &translated_point, figure->bump_map.texture, res);
}
