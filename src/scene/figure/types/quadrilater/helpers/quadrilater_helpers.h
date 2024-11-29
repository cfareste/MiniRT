/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/28 23:47:13 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"

float	get_quad_rotated_point(t_vector *quad_normal, t_vector *quad_right,
			t_point *rotated_point);
