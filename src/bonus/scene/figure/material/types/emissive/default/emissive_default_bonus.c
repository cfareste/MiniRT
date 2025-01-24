/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive_default_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:17:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/material/material_bonus.h"

t_material	new_emissive_default_mat(void)
{
	t_emissive_attrs	attrs;
	t_material			emissive_material;

	attrs.intensity = 5;
	emissive_material = new_emissive_mat(&attrs);
	return (emissive_material);
}
