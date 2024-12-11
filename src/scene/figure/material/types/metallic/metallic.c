/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:08:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 11:48:22 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
#include "scene/figure/material/material.h"
#include "render/strategies/shared/strategies_shared.h"
#include "scene/figure/material/helpers/material_helpers.h"

static int	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint32_t *seed)
{
	params->attrs = params->hit_record.figure->material.metallic_attrs;
	return (metallic_scatter(render, params, direct_light, seed));
}

t_material	new_metallic_mat(t_metallic_attrs *attrs)
{
	t_material	metallic_mat;

	metallic_mat.type = METALLIC;
	metallic_mat.scatter = scatter;
	metallic_mat.metallic_attrs = ft_calloc(1, sizeof(t_metallic_attrs));
	if (!metallic_mat.metallic_attrs)
		throw_sys_error("trying to allocate metallic attributes");
	metallic_mat.metallic_attrs->roughness = attrs->roughness;
	return (metallic_mat);
}
