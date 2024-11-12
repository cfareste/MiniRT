/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:44:36 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/12 01:50:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bump_map.h"
#include "render/utils/color/color.h"

void	get_pixel_normal(uint8_t *pixel, t_bump_map_format format,
	t_vector *res)
{
	t_color	pixel_color;

	pixel_color.red = *pixel / (float) 255;
	pixel_color.green = *(pixel + 1) / (float) 255;
	pixel_color.blue = *(pixel + 2) / (float) 255;
	res->x = (pixel_color.red / 0.5) - 1;
	res->y = (pixel_color.green / 0.5) - 1;
	if (format == DIRECTX)
		res->y *= -1;
	res->z = (pixel_color.blue / 0.5) - 1;
}
