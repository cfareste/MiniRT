/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:24:11 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 13:24:32 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material.h"

t_material	new_metallic_default_mat(void)
{
	t_metallic_attrs	attrs;
	t_material			metallic_material;

	attrs.roughness = 0;
	metallic_material = new_metallic_mat(&attrs);
	return (metallic_material);
}
