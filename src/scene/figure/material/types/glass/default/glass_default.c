/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:27:51 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 13:29:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material.h"

t_material	new_glass_default_mat(void)
{
	t_glass_attrs	attrs;
	t_material		glass_material;

	attrs.refractive_index = GLASS_REFRACTIVE_INDEX;
	attrs.transparency = 1;
	glass_material = new_glass_mat(&attrs);
	return (glass_material);
}
