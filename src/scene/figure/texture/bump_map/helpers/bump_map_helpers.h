/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:47:43 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/12 23:44:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../bump_map.h"
#include "render/utils/point/point.h"
#include "render/utils/color/color.h"

void	get_pixel_normal(uint8_t *pixel, t_bump_map_format format,
			t_vector *res);

void	rotate_bump_to_point_position(t_point *point, t_vector *res);
