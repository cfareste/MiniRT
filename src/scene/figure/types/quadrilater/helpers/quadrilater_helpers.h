/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 12:04:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"

float	get_quad_rotated_point(t_vector *quad_normal, t_vector *quad_right,
			t_point *rotated_point);

void	rotate_quadrilater(t_figure *quad, t_camera *camera, t_point *factor);
