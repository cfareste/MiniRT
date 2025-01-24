/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic_default_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:24:11 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material_bonus.h"

t_material	new_metallic_default_mat(void)
{
	t_metallic_attrs	attrs;
	t_material			metallic_material;

	attrs.roughness = 0;
	metallic_material = new_metallic_mat(&attrs);
	return (metallic_material);
}
