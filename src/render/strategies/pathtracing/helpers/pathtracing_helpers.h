/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing_helpers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:15:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 18:15:26 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/light/utils/light_utils.h"

void	pt_compute_direct_light_comps(t_direct_lighting *direct_lighting,
			t_light *light, t_color *color);