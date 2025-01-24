/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:35:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/strategies/shared/strategies_shared_bonus.h"
#include "scene/figure/material/helpers/material_helpers_bonus.h"

t_material	new_diffuse_mat(void)
{
	t_material	diffuse_mat;

	diffuse_mat.type = DIFFUSE;
	diffuse_mat.material_attrs = NULL;
	diffuse_mat.scatter = diffuse_scatter;
	return (diffuse_mat);
}
