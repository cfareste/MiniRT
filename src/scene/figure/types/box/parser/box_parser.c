/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:11:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/27 01:25:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"
#include "render/utils/vector/parser/vector_parser.h"

void	check_box_parsing(t_parser_ctx *ctx, t_figure *box)
{
	check_ori_vector_parsing(ctx, &box->bo_attrs->orientation);
	if (box->bo_attrs->width <= 0)
		throw_parse_err(ctx, "Box width must be a positive value");
	if (box->bo_attrs->height <= 0)
		throw_parse_err(ctx, "Box height must be a positive value");
	if (box->bo_attrs->length <= 0)
		throw_parse_err(ctx, "Box length must be a positive value");
}
