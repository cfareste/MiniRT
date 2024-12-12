/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:09:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:10:49 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->emissive_attrs->intensity < 0)
		throw_parse_err(ctx, "Emissive intensity must be a positive value");
}

void	parse_emissive(t_parser_ctx *ctx, char *str, t_material *material)
{
	t_emissive_attrs	attrs;

	if (!str)
		throw_parse_err(ctx, "Missing emissive intensity attribute");
	attrs.intensity = parse_double(ctx, str);
	*material = new_emissive_mat(&attrs);
	check_parsing(ctx, material);
}
