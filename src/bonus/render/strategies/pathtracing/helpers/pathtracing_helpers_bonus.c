/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing_helpers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:11:36 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/light/utils/light_utils_bonus.h"

void	pt_compute_direct_light_comps(t_direct_lighting *direct_lighting,
	t_light *light, t_color *color)
{
	if (direct_lighting->scatter_type == DIFFUSE)
		compute_diffuse(&direct_lighting->diffuse, 1.0, light, color);
	else if (direct_lighting->scatter_type == METALLIC)
		compute_specular(&direct_lighting->specular, 1.0, light, color);
}
