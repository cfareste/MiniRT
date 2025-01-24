/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector_bonus.h"

typedef t_coordinates	t_point;

void	translate_point(t_point *point, t_vector *direction, float scalar,
			t_point *res);

t_point	wrap_point(double x, double y, double z);