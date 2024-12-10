/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:31:18 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:25:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "libft.h"

static void	check_cylinder_parsing(t_parser_ctx *ctx, t_figure *cylinder)
{
	check_ori_vector_parsing(ctx, &cylinder->cy_attrs->orientation);
	if (cylinder->cy_attrs->radius <= 0)
		throw_parse_err(ctx, "Cylinder diameter must be a positive value");
	else if (cylinder->cy_attrs->height <= 0)
		throw_parse_err(ctx, "Cylinder height must be a positive value");
}

t_figure	*parse_cylinder(t_parser_ctx *ctx, char **parts)
{
	t_figure			*cylinder;
	t_point				position;
	t_color				color;
	t_cylinder_attrs	cy_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 3)
		throw_parse_err(ctx, "Missing some cylinder parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1], &cy_attrs.orientation);
	cy_attrs.radius = parse_double(ctx, parts[FIG_LAST_ATT + 2]) / 2.0f;
	cy_attrs.height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	parse_color(ctx, parts[FIG_LAST_ATT + 4], &color);
	cylinder = new_cylinder(&position, &color, &cy_attrs);
	set_figure_optionals(ctx, cylinder, &parts[FIG_LAST_ATT + 5]);
	check_cylinder_parsing(ctx, cylinder);
	return (cylinder);
}
