/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:46:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:18:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->metallic_attrs->roughness < 0
		|| material->metallic_attrs->roughness > 1)
		throw_parse_err(ctx, "Metallic roughness must be in range [0,1]");
}

void	parse_metallic(t_parser_ctx *ctx, char *str, t_material *material)
{
	t_metallic_attrs	attrs;

	if (!str)
		throw_parse_err(ctx, "Missing metallic roughness attribute");
	attrs.roughness = parse_double(ctx, str);
	*material = new_metallic_mat(&attrs);
	check_parsing(ctx, material);
}
