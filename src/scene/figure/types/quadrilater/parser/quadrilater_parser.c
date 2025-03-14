/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:07:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 19:54:55 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "libft.h"

static void	check_quadrilater_parsing(t_parser_ctx *ctx, t_figure *quad)
{
	check_ori_vector_parsing(ctx, &quad->qu_attrs->right);
	check_ori_vector_parsing(ctx, &quad->qu_attrs->up);
	if (quad->qu_attrs->width <= 0)
		throw_parse_err(ctx, "Quadrilater width must be a positive value");
	if (quad->qu_attrs->height <= 0)
		throw_parse_err(ctx, "Quadrilater height must be a positive value");
}

t_figure	*parse_quadrilater(t_parser_ctx *ctx, char **parts)
{
	t_figure			*quadrilater;
	t_point				position;
	t_color				color;
	t_quadrilater_attrs	quad_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 4)
		throw_parse_err(ctx, "Missing some quadrilater parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1], &quad_attrs.right);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 2], &quad_attrs.up);
	quad_attrs.width = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	quad_attrs.height = parse_double(ctx, parts[FIG_LAST_ATT + 4]);
	parse_color(ctx, parts[FIG_LAST_ATT + 5], &color);
	quadrilater = new_quadrilater(&position, &color, &quad_attrs);
	set_figure_optionals(ctx, quadrilater, &parts[FIG_LAST_ATT + 6]);
	check_quadrilater_parsing(ctx, quadrilater);
	return (quadrilater);
}
