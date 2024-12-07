/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:08:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 20:07:25 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
#include "scene/figure/material/material.h"
#include "parser/helpers/parser_helper.h"
#include "render/strategies/shared/strategies_shared.h"
#include "scene/figure/material/helpers/material_helpers.h"

static int	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	params->attrs = params->hit_record.figure->material.metallic_attrs;
	return (metallic_scatter(render, params, direct_light, seed));
}

static void	check_parsing(t_parser_ctx *ctx, t_material *material)
{
	if (material->metallic_attrs->roughness < 0
		|| material->metallic_attrs->roughness > 1)
		throw_parse_err(ctx, "Metallic roughness must be in range [0,1]");
}

void	parse_metallic(t_parser_ctx *ctx, char *attrs_str, t_material *material)
{
	if (!attrs_str)
		throw_parse_err(ctx, "Missing metallic roughness attribute");
	material->type = METALLIC;
	material->metallic_attrs = ft_calloc(1, sizeof(t_metallic_attrs));
	if (!material->metallic_attrs)
		throw_sys_error("trying to allocate metallic attributes");
	material->metallic_attrs->roughness = parse_double(ctx, attrs_str);
	material->scatter = scatter;
	check_parsing(ctx, material);
}
