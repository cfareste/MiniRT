/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass_default_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:27:51 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material_bonus.h"

t_material	new_glass_default_mat(void)
{
	t_glass_attrs	attrs;
	t_material		glass_material;

	attrs.refractive_index = GLASS_REFRACTIVE_INDEX;
	attrs.transparency = 1;
	glass_material = new_glass_mat(&attrs);
	return (glass_material);
}
