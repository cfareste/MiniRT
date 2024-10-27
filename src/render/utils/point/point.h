/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

typedef t_coordinates	t_point;

void	translate_point(t_point *point, t_vector *direction, float scalar,
			t_point *res);
