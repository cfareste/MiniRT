/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/05 23:24:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "parser/parser.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "../light.h"
#include "parser/helpers/parser_helper.h"
#include "scene/scene.h"
#include "scene/figure/types/sphere/texture/bump_map_sphere.h"
#include "scene/figure/texture/texel/texel.h"
#include <math.h>

void	parse_ambient_light(t_parser_ctx *ctx, char **parts, t_light **light)
{
	if (*light)
		throw_parse_err(ctx, "Multiple ambient lights are not allowed");
	if (!parts[1] || !parts[2])
		throw_parse_err(ctx, "Missing ambient light params");
	*light = ft_calloc(1, sizeof(t_light));
	if (!*light)
		throw_sys_error("trying to allocate ambient light");
	(*light)->type = AMBIENT_LIGHT_ID;
	(*light)->brightness = parse_double(ctx, parts[1]);
	parse_color(ctx, parts[2], &(*light)->color);
	if ((*light)->brightness > 1.0 || (*light)->brightness < 0.0)
		throw_parse_err(ctx,
			"Brightness param for ambient light must be in range [0.0,1.0]");
}

static void	parse_polar_coords(t_point *point, t_polar_coordinates *coords)
{
	if (point->x < 0.0)
		coords->latitude = -coords->latitude;
	if (point->y > 0.0)
		coords->longitude = -coords->longitude;
}

static void	get_sky_box_color(t_figure *figure, t_point *point,
	t_texture *texture, t_color *color)
{
	t_polar_coordinates	coords;
	t_vector			texture_dims;
	uint8_t				*pixel;
	t_texel				texel;
	float				point_radius;

	get_polar_coordinates(point, figure, &coords);
	point_radius = sqrt(pow(point->x, 2) + pow(point->z, 2));
	texture_dims.x = texture->mlx->width
		* (point_radius / figure->sp_attrs->radius);
	texture_dims.y = texture->mlx->height;
	parse_polar_coords(point, &coords);
	texel.x = (coords.latitude * (texture->mlx->width / texture_dims.x));
	texel.y = coords.longitude + (texture_dims.y / 2.0);
	if (coords.latitude < 0)
		texel.x += texture->mlx->width;
	texel.x = ft_clamp(texel.x, 0, texture->mlx->width - 1);
	texel.y = ft_clamp(texel.y, 0, texture->mlx->height - 1);
	pixel = texture->mlx->pixels
		+ ((4 * texture->mlx->width) * texel.y) + (4 * texel.x);
	color->red = *pixel / 255.0;
	color->green = *(pixel + 1) / 255.0;
	color->blue = *(pixel + 2) / 255.0;
	color->alpha = 1.0;
}

void	get_sky_color(t_scene *scene, t_ray *ray, t_light *ambient_light,
	t_color *sky_color)
{
	t_hit_record	hit_record;
	t_vector		translated_point;
	t_color			scene_sky_color;

	if (scene->settings.sky_box
		&& scene->settings.sky_box->hit(scene->settings.sky_box, ray,
			&hit_record.distance))
	{
		translate_point(&ray->origin, &ray->direction, hit_record.distance,
			&hit_record.point);
		get_vector(&hit_record.point, &scene->camera->position,
			&translated_point);
		get_sky_box_color(scene->settings.sky_box, &translated_point,
			scene->settings.sky_box->bump_map.texture, &scene_sky_color);
	}
	else
		scene_sky_color = scene->settings.sky_color;
	multiply_color_scalar(&scene_sky_color, ambient_light->brightness,
		sky_color);
	sky_color->alpha = 1.0;
}
