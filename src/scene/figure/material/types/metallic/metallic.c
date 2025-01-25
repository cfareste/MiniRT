/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:08:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "render/strategies/shared/strategies_shared.h"
#include "scene/figure/material/helpers/material_helpers.h"

static int	scatter(t_render *render, t_scatter_params *params,
	t_color *direct_light, uint64_t *seed)
{
	params->attrs = params->hit_record.figure->material.metallic_attrs;
	return (metallic_scatter(render, params, direct_light, seed));
}

static char	*compose_metallic(t_material *material)
{
	char	*str;

	str = NULL;
	join_format_str(&str, "metallic:",
		ft_dtoa(material->metallic_attrs->roughness, 3), SEP);
	return (str);
}

t_material	new_metallic_mat(t_metallic_attrs *attrs)
{
	t_material	metallic_mat;

	metallic_mat.type = METALLIC;
	metallic_mat.scatter = scatter;
	metallic_mat.compose = compose_metallic;
	metallic_mat.metallic_attrs = ft_calloc(1, sizeof(t_metallic_attrs));
	if (!metallic_mat.metallic_attrs)
		throw_sys_error("trying to allocate metallic attributes");
	metallic_mat.metallic_attrs->roughness = attrs->roughness;
	return (metallic_mat);
}
