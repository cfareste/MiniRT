/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:23:54 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:45:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/light/utils/light_utils.h"

void	rt_compute_direct_light_comps(t_direct_lighting *direct_lighting,
	t_light *light, t_color *color)
{
	compute_diffuse(&direct_lighting->diffuse, 0.5, light, color);
}
