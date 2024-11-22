/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 00:58:19 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

typedef t_coordinates	t_point;

void	translate_point(t_point *point, t_vector *direction, float scalar,
			t_point *res);

t_point	wrap_point(double x, double y, double z);