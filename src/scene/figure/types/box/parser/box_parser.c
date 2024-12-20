/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:11:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/20 14:09:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "scene/figure/parser/figure_parser.h"
#include "libft.h"

static void	check_box_parsing(t_parser_ctx *ctx, t_figure *box)
{
	check_ori_vector_parsing(ctx, &box->bo_attrs->faces[0].attrs.right);
	check_ori_vector_parsing(ctx, &box->bo_attrs->faces[0].attrs.up);
	if (box->bo_attrs->width <= 0)
		throw_parse_err(ctx, "Box width must be a positive value");
	if (box->bo_attrs->height <= 0)
		throw_parse_err(ctx, "Box height must be a positive value");
	if (box->bo_attrs->length <= 0)
		throw_parse_err(ctx, "Box length must be a positive value");
}

t_figure	*parse_box(t_parser_ctx *ctx, char **parts)
{
	t_figure	*box;
	t_point		position;
	t_color		color;
	t_box_attrs	box_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 5)
		throw_parse_err(ctx, "Missing some box parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1],
		&box_attrs.faces[0].attrs.right);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 2],
		&box_attrs.faces[0].attrs.up);
	box_attrs.width = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	box_attrs.height = parse_double(ctx, parts[FIG_LAST_ATT + 4]);
	box_attrs.length = parse_double(ctx, parts[FIG_LAST_ATT + 5]);
	parse_color(ctx, parts[FIG_LAST_ATT + 6], &color);
	box = new_box(&position, &color, &box_attrs);
	set_figure_optionals(ctx, box, &parts[FIG_LAST_ATT + 7]);
	check_box_parsing(ctx, box);
	return (box);
}
