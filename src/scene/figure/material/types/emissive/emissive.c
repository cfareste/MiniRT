/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:41:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/18 17:09:29 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "utils/utils_bonus.h"
#include "render/render_bonus.h"
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

static char	*compose_emissive(t_material *material)
{
	char	*str;

	str = NULL;
	join_format_str(&str, "emissive:",
		ft_dtoa(material->emissive_attrs->intensity, 3), SEP);
	return (str);
}

t_material	new_emissive_mat(t_emissive_attrs *attrs)
{
	t_material	emissive_mat;

	emissive_mat.type = EMISSIVE;
	emissive_mat.scatter = scatter;
	emissive_mat.compose = compose_emissive;
	emissive_mat.emissive_attrs = ft_calloc(1, sizeof(t_emissive_attrs));
	if (!emissive_mat.emissive_attrs)
		throw_sys_error("trying to allocate emissive attributes");
	emissive_mat.emissive_attrs->intensity = attrs->intensity;
	return (emissive_mat);
}
