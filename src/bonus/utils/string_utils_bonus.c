/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:21:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 15:57:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/color/color_bonus.h"
#include "render/utils/coordinates/coordinates_bonus.h"
#include "utils/utils_bonus_bonus.h"
#include "libft.h"

char	*colortoa(t_color *color)
{
	char	*red_str;
	char	*green_str;
	char	*blue_str;
	char	*color_str;

	red_str = ft_itoa(color->red * 255);
	green_str = ft_itoa(color->green * 255);
	blue_str = ft_itoa(color->blue * 255);
	if (!red_str || !green_str || !blue_str)
		throw_sys_error("allocating color components strings");
	color_str = NULL;
	push_str(&color_str, red_str, throw_sys_error, "pushing color component");
	push_char(&color_str, ',', throw_sys_error, "pushing color component");
	push_str(&color_str, green_str, throw_sys_error, "pushing color component");
	push_char(&color_str, ',', throw_sys_error, "pushing color component");
	push_str(&color_str, blue_str, throw_sys_error, "pushing color component");
	free(red_str);
	free(green_str);
	free(blue_str);
	return (color_str);
}

char	*coordtoa(t_coordinates *coords, int precision)
{
	char	*x_str;
	char	*y_str;
	char	*z_str;
	char	*coords_str;

	x_str = ft_dtoa(coords->x, precision);
	y_str = ft_dtoa(coords->y, precision);
	z_str = ft_dtoa(coords->z, precision);
	if (!x_str || !y_str || !z_str)
		throw_sys_error("allocating coordinates components strings");
	coords_str = NULL;
	push_str(&coords_str, x_str, throw_sys_error, "pushing coords component");
	push_char(&coords_str, ',', throw_sys_error, "pushing coords component");
	push_str(&coords_str, y_str, throw_sys_error, "pushing coords component");
	push_char(&coords_str, ',', throw_sys_error, "pushing coords component");
	push_str(&coords_str, z_str, throw_sys_error, "pushing coords component");
	free(x_str);
	free(y_str);
	free(z_str);
	return (coords_str);
}

void	join_format_str(char **buffer, char *prefix, char *str, char separator)
{
	if (!str)
		throw_sys_error("allocating composer setting in buffer");
	if (prefix)
		push_str(buffer, prefix, throw_sys_error, "joining buffer with prefix");
	push_str(buffer, str, throw_sys_error, "joining buffer with string");
	if (separator != '\0')
		push_char(buffer, separator, throw_sys_error, "joining sep with buff");
	free(str);
}
