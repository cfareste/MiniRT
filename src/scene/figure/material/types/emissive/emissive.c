/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:41:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 13:34:36 by cfidalgo         ###   ########.fr       */
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
	if (material->emissive_attrs->intensity < 0)
		throw_parse_err(ctx, "Emissive intensity must be a positive value");
}

void	parse_emissive(t_parser_ctx *ctx, char *attrs_str, t_material *material)
{
	if (!attrs_str)
		throw_parse_err(ctx, "Missing emissive intensity attribute");
	material->type = EMISSIVE;
	material->emissive_attrs = ft_calloc(1, sizeof(t_emissive_attrs));
	if (!material->emissive_attrs)
		throw_sys_error("trying to allocate emissive attributes");
	material->emissive_attrs->intensity = parse_double(ctx, attrs_str);
	material->scatter = scatter;
	check_parsing(ctx, material);
}
