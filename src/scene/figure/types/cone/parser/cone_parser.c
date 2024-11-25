/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:22:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 16:54:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_cone_parsing(t_parser_ctx *ctx, t_figure *cone)
{
	check_ori_vector_parsing(ctx, &cone->co_attrs->orientation);
	if (cone->co_attrs->radius <= 0)
		throw_parse_err(ctx, "Cone diameter must be a positive value");
	else if (cone->co_attrs->height <= 0)
		throw_parse_err(ctx, "Cone height must be a positive value");
}
