/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:35:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 13:42:32 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"
#include "render/utils/point/point.h"
#include "render/utils/random/random.h"
#include "scene/figure/material/material.h"
#include "scene/light/light.h"
#include "render/strategies/shared/strategies_shared.h"
#include "scene/figure/material/helpers/material_helpers.h"
#include "float.h"

void	parse_diffuse(t_material *material)
{
	material->type = DIFFUSE;
	material->material_attrs = NULL;
	material->scatter = diffuse_scatter;
}
