/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:11:36 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 19:22:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/light/utils/light_utils.h"

void	pt_compute_direct_light_comps(t_direct_lighting *direct_lighting,
	t_light *light, t_color *color)
{
	t_figure	*figure;

	figure = direct_lighting->figure;
	if (figure->material.type != METALLIC)
		compute_diffuse(&direct_lighting->diffuse, 1.0, light, color);
	if (figure->material.type != DIFFUSE)
		compute_specular(&direct_lighting->specular, 1.0, light, color);
}
