/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:31:18 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_cylinder_parsing(t_parser_ctx *ctx, t_figure *cylinder)
{
	check_ori_vector_parsing(ctx, &cylinder->cy_attrs->orientation);
	if (cylinder->cy_attrs->radius <= 0)
		throw_parse_err(ctx, "Cylinder diameter must be a positive value");
	else if (cylinder->cy_attrs->height < 0)
		throw_parse_err(ctx, "Cylinder height must be a positive value");
}
