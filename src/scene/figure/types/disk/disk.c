/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/24 23:18:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "utils/utils_bonus.h"
#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "scene/figure/types/disk/parser/disk_parser.h"
#include "scene/figure/pattern/helpers/pattern_helpers.h"
#include "scene/figure/types/disk/texture/bump_map_disk.h"
#include "render/utils/reference_system/reference_system.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

static void	print_attrs(void *param)
{
	t_disk_attrs	*attrs;

	attrs = param;
	printf("%f | %f, %f, %f", attrs->radius,
		attrs->orientation.x, attrs->orientation.y, attrs->orientation.z);
}

static int	hit(t_figure *figure, t_ray *ray, float *distance)
{
	t_figure		plane;
	t_plane_attrs	pl_attrs;
	t_point			hit_point;
	t_vector		hit_to_center;
	float			base_distance;

	base_distance = FLT_MAX;
	pl_attrs.orientation = figure->di_attrs->orientation;
	set_plane(&plane, &figure->position, &pl_attrs);
	if (!plane.hit(&plane, ray, &base_distance))
		return (0);
	translate_point(&ray->origin, &ray->direction, base_distance, &hit_point);
	get_vector(&hit_point, &figure->position, &hit_to_center);
	if (base_distance <= ray->bounds.min || base_distance >= ray->bounds.max
		|| sqrt(dot(&hit_to_center, &hit_to_center)) > figure->di_attrs->radius)
		return (0);
	*distance = base_distance;
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

t_figure	*parse_disk(t_parser_ctx *ctx, char **parts)
{
	t_figure	*disk;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 2)
		throw_parse_err(ctx, "Missing some disk parameter");
	disk = parse_figure(ctx, parts, FIG_LAST_ATT + 3);
	disk->di_attrs = ft_calloc(1, sizeof(t_disk_attrs));
	if (!disk->di_attrs)
		throw_sys_error("trying to allocate disk attributes");
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&disk->di_attrs->orientation);
	disk->di_attrs->radius = parse_double(ctx, parts[FIG_LAST_ATT + 2]) / 2.0;
	normalize(&disk->di_attrs->orientation);
	disk->print_attrs = print_attrs;
	disk->hit = hit;
	disk->normal = normal;
	disk->get_color_pattern = get_color;
	check_disk_parsing(ctx, disk);
	return (disk);
}
