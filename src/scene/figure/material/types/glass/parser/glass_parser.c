/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:57:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:24:57 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"
#include "libft.h"

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->glass_attrs->refractive_index < 1)
		throw_parse_err(ctx, "Refraction index must be greater than 1");
	if (material->glass_attrs->transparency < 0
		|| material->glass_attrs->transparency > 1)
		throw_parse_err(ctx, "Glass transparency must be in range [0,1]");
}

void	parse_glass(t_parser_ctx *ctx, char **parts, t_material *material)
{
	t_glass_attrs	attrs;

	if (ft_matrix_len(parts) < 2)
		throw_parse_err(ctx, "Missing some glass attributes");
	attrs.refractive_index = parse_double(ctx, parts[0]);
	attrs.transparency = parse_double(ctx, parts[1]);
	*material = new_glass_mat(&attrs);
	check_parsing(ctx, material);
}
