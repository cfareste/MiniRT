/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_pattern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:33:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/27 22:39:38 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

int	get_color_index(t_color *first_color, t_color *color)
{
	if (first_color->red == color->red && first_color->green == color->green
		&& first_color->blue == color->blue)
		return (0);
	return (1);
}

void	add_pattern_offset(t_figure *box, int face_index, t_color *res)
{
	int	pattern_index;

	pattern_index = get_color_index(&box->pattern.colors[0], res);
	if (face_index >= 1 && face_index <= 4)
		pattern_index = !pattern_index;
	*res = box->pattern.colors[pattern_index];
}
