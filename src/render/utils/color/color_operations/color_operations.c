/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:24:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/08 17:17:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render/utils/color/color.h"

void	sum_color_scalar(t_color *color, float scalar, t_color *res)
{
	res->red = color->red + scalar;
	res->green = color->green + scalar;
	res->blue = color->blue + scalar;
}

void	sum_colors(t_color *first_color, t_color *second_color, t_color *res)
{
	res->red = first_color->red + second_color->red;
	res->green = first_color->green + second_color->green;
	res->blue = first_color->blue + second_color->blue;
}

void	mix_colors(t_color *first_color, t_color *second_color, t_color *res)
{
	res->red = first_color->red * second_color->red;
	res->green = first_color->green * second_color->green;
	res->blue = first_color->blue * second_color->blue;
}

void	multiply_color_scalar(t_color *color, float scalar, t_color *res)
{
	res->red = color->red * scalar;
	res->green = color->green * scalar;
	res->blue = color->blue * scalar;
}
