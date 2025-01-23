/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_sphere.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 19:40:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/types/sphere/helpers/polar_coordinates.h"

void	get_polar_coordinates(t_point *point, t_figure *sphere,
			t_polar_coordinates *coords);

void	get_sphere_bump_normal(t_figure *figure, t_point *point, t_vector *res);
