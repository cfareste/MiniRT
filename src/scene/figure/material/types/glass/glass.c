/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:50:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 13:50:57 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "scene/figure/material/material.h"

static void	scatter(t_ray *ray, t_hit_record *hit_record, uint32_t *seed)
{
	(void) ray;
	(void) hit_record;
	(void) seed;
}

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->glass_attrs->refractive_index < 1)
		throw_parse_err(ctx, "Refraction index must be greater than 1");
	if (material->glass_attrs->transparency < 0
		|| material->glass_attrs->transparency > 1)
		throw_parse_err(ctx, "Glass transparency must be in range [0,1]");
}

void	parse_glass(t_parser_ctx *ctx, char **attrs, t_material *material)
{
	if (ft_matrix_len(attrs) < 2)
		throw_parse_err(ctx, "Missing some glass attributes");
	material->type = GLASS;
	material->glass_attrs = ft_calloc(1, sizeof(t_glass_attrs));
	if (!material->glass_attrs)
		throw_sys_error("trying to allocate glass attributes");
	material->glass_attrs->refractive_index = parse_double(ctx, attrs[0]);
	material->glass_attrs->transparency = parse_double(ctx, attrs[1]);
	material->scatter = scatter;
	check_parsing(ctx, material);
}
