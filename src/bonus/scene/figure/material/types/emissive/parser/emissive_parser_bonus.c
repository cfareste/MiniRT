/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive_parser_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:09:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/helpers/parser_helper_bonus.h"
#include "scene/figure/material/material_bonus.h"

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
