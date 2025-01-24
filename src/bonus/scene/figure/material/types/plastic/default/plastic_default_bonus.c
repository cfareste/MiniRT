/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic_default_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:21:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material_bonus.h"

t_material	new_plastic_default_mat(void)
{
	t_plastic_attrs	attrs;
	t_material		plastic_material;

	attrs.roughness = 0;
	attrs.specular_index = 0.2;
	plastic_material = new_plastic_mat(&attrs);
	return (plastic_material);
}
