/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_sphere.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/14 17:23:49 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"

void	get_sphere_bump_normal(t_figure *figure, t_point *point, t_vector *res);