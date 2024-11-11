/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_pattern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:33:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/11 00:52:05 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"

typedef struct s_polar_coordinates
{
	float	latitude;
	float	longitude;
}	t_polar_coordinates;

void	get_sphere_pattern(t_figure *figure, t_point *point, t_color *res);
