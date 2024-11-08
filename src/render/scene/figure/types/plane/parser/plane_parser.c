/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:11:31 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/08 15:49:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "plane_parser.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "render/utils/reference_system/reference_system.h"
#include "../../../parser/figure_parser.h"
#include "../plane.h"
#include <math.h>

static void	check_parsing(t_parser_ctx *ctx, t_figure *plane)
{
	check_ori_vector_parsing(ctx, &plane->pl_attrs->orientation);
}

static void	get_color(t_figure *figure, t_point *point, t_color *res)
{
	int	x_index_square;
	int	y_index_square;
	int	pattern_index;

	x_index_square = (int)(fabs(point->x) / figure->pattern.dimension);
	y_index_square = (int)(fabs(point->y) / figure->pattern.dimension);
	if (point->x < 0.0)
		x_index_square++;
	if (point->y < 0.0)
		y_index_square++;
	pattern_index = ((x_index_square % 2) + (y_index_square % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}

t_figure	*parse_plane(t_parser_ctx *ctx, char **parts)
{
	t_figure	*plane;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 1)
		throw_parse_err(ctx, "Missing some plane parameter");
	plane = parse_figure(ctx, parts, FIG_LAST_ATT + 2);
	plane->pl_attrs = ft_calloc(1, sizeof(t_plane_attrs));
	if (!plane->pl_attrs)
		throw_sys_error("trying to allocate plane attributes");
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&plane->pl_attrs->orientation);
	normalize(&plane->pl_attrs->orientation);
	set_plane(plane, &plane->position, plane->pl_attrs);
	plane->get_color_pattern = get_color;
	check_parsing(ctx, plane);
	return (plane);
}
