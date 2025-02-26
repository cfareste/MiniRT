/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:55:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/11 00:52:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include <math.h>

void	get_plane_pattern(t_figure *figure, t_point *point, t_color *res)
{
	int	x_index_square;
	int	y_index_square;
	int	pattern_index;

	x_index_square = (int)(fabs(point->x) / figure->pattern.dimension);
	y_index_square = (int)(fabs(point->y) / figure->pattern.dimension);
	if (point->x < 0.0)
		x_index_square++;
	if (point->y < 0.0)
		y_index_square++;
	pattern_index = ((x_index_square % 2) + (y_index_square % 2)) % 2;
	*res = figure->pattern.colors[pattern_index];
}
