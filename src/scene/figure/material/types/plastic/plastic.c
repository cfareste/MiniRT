/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:01:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 17:22:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
#include "scene/figure/material/material.h"
#include "parser/helpers/parser_helper.h"

static void	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	(void) render;
	(void) params;
	(void) direct_light;
	(void) seed;
}

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->plastic_attrs->specular_index < 0
		|| material->plastic_attrs->specular_index > 1)
		throw_parse_err(ctx, "Specular index must be in range [0,1]");
	if (material->plastic_attrs->roughness < 0
		|| material->plastic_attrs->roughness > 1)
		throw_parse_err(ctx, "Plastic roughness must be in range [0,1]");
}

void	parse_plastic(t_parser_ctx *ctx, char **attrs_str, t_material *material)
{
	if (ft_matrix_len(attrs_str) < 2)
		throw_parse_err(ctx, "Missing some plastic attributes");
	material->type = PLASTIC;
	material->plastic_attrs = ft_calloc(1, sizeof(t_plastic_attrs));
	if (!material->plastic_attrs)
		throw_sys_error("trying to allocate plastic attributes");
	material->plastic_attrs->specular_index = parse_double(ctx, attrs_str[0]);
	material->plastic_attrs->roughness = parse_double(ctx, attrs_str[1]);
	material->scatter = scatter;
	check_parsing(ctx, material);
}
