/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:21:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:19 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material.h"

t_material	new_plastic_default_mat(void)
{
	t_plastic_attrs	attrs;
	t_material		plastic_material;

	attrs.roughness = 0;
	attrs.specular_index = 0.2;
	plastic_material = new_plastic_mat(&attrs);
	return (plastic_material);
}
