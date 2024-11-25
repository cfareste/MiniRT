/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:07:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 19:23:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_quadrilater_parsing(t_parser_ctx *ctx, t_figure *quad)
{
	check_ori_vector_parsing(ctx, &quad->qu_attrs->orientation);
	if (quad->qu_attrs->width <= 0)
		throw_parse_err(ctx, "Quadrilater width must be a positive value");
	if (quad->qu_attrs->height <= 0)
		throw_parse_err(ctx, "Quadrilater height must be a positive value");
}
