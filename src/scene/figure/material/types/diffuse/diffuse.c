/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:35:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:13:42 by cfidalgo         ###   ########.fr       */
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

t_material	new_diffuse_mat(void)
{
	t_material	diffuse_mat;

	diffuse_mat.type = DIFFUSE;
	diffuse_mat.material_attrs = NULL;
	diffuse_mat.scatter = diffuse_scatter;
	return (diffuse_mat);
}
