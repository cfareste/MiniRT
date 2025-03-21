/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:38:31 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:25:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"
#include "libft.h"

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->plastic_attrs->specular_index < 0
		|| material->plastic_attrs->specular_index > 1)
		throw_parse_err(ctx, "Specular index must be in range [0,1]");
	if (material->plastic_attrs->roughness < 0
		|| material->plastic_attrs->roughness > 1)
		throw_parse_err(ctx, "Plastic roughness must be in range [0,1]");
}

void	parse_plastic(t_parser_ctx *ctx, char **parts, t_material *material)
{
	t_plastic_attrs	attrs;

	if (ft_matrix_len(parts) < 2)
		throw_parse_err(ctx, "Missing some plastic attributes");
	attrs.specular_index = parse_double(ctx, parts[0]);
	attrs.roughness = parse_double(ctx, parts[1]);
	*material = new_plastic_mat(&attrs);
	check_parsing(ctx, material);
}
