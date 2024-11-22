/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:41:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 20:10:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

static int	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	(void) render;
	(void) params;
	(void) direct_light;
	(void) seed;
	return (1);
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
