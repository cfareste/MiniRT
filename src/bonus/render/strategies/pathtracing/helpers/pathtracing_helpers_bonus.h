/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing_helpers_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:15:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/light/utils/light_utils_bonus.h"

void	pt_compute_direct_light_comps(t_direct_lighting *direct_lighting,
			t_light *light, t_color *color);