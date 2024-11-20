/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:23:54 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 19:22:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/light/utils/light_utils.h"

void	rt_compute_direct_light_comps(t_direct_lighting *direct_lighting,
	t_light *light, t_color *color)
{
	compute_diffuse(&direct_lighting->diffuse, 0.5, light, color);
	compute_specular(&direct_lighting->specular, 0.5, light, color);
}
