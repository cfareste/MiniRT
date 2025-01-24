/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "scene/figure/parser/figure_parser_bonus.h"
#include "scene/figure/helpers/figure_helpers_bonus.h"
#include "scene/figure/operations/figure_operations_bonus.h"
#include "scene/figure/pattern/helpers/pattern_helpers_bonus.h"
#include "scene/figure/types/disk/texture/bump_map_disk_bonus.h"
#include "scene/figure/types/disk/composer/disk_composer_bonus.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

static void	rotate(t_figure *figure, t_camera *camera, t_point *factor)
{
	rotate_figure(&figure->di_attrs->orientation, camera, factor);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_vector	center_to_hit;
	float		hit_distance;
	float		hit_radius;

	hit_distance = get_plane_center_to_hit(&figure->di_attrs->orientation,
			&figure->position, ray, &center_to_hit);
	if (hit_distance < 0.0)
		return (0);
	hit_radius = sqrt(dot(&center_to_hit, &center_to_hit));
	if (hit_distance < 0.0 || hit_radius > figure->di_attrs->radius)
		return (0);
	*distance = hit_distance;
	return (1);
}

static void	normal(t_figure *figure, t_point *point, t_vector *res)
{
	if (figure->bump_map.texture)
		get_disk_bump_normal(figure, point, res);
	else
		*res = figure->di_attrs->orientation;
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	t_point			rotated_point;
	t_base_attrs	base_attrs;

	base_attrs.radius = figure->di_attrs->radius;
	base_attrs.base_distance = 0.0;
	get_vector(point, &figure->position, &rotated_point);
	rotate_reference_system(&figure->di_attrs->orientation, NULL,
		&rotated_point);
	get_base_pattern(figure, &rotated_point, &base_attrs, res);
}

t_figure	*new_disk(t_point *pos, t_color *color, t_disk_attrs *disk_attrs)
{
	t_figure	*disk;

	disk = new_figure(DISK_ID, pos, color);
	disk->di_attrs = ft_calloc(1, sizeof(t_disk_attrs));
	if (!disk->di_attrs)
		throw_sys_error("trying to allocate disk attributes");
	disk->di_attrs->orientation = disk_attrs->orientation;
	normalize(&disk->di_attrs->orientation);
	disk->di_attrs->radius = disk_attrs->radius;
	disk->hit = hit;
	disk->normal = normal;
	disk->rotate = rotate;
	disk->compose = compose_disk;
	disk->get_color_pattern = get_color;
	return (disk);
}
