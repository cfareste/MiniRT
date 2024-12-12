/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:17:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:22 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material.h"

t_material	new_emissive_default_mat(void)
{
	t_emissive_attrs	attrs;
	t_material			emissive_material;

	attrs.intensity = 5;
	emissive_material = new_emissive_mat(&attrs);
	return (emissive_material);
}
