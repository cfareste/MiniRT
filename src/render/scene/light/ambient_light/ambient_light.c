/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 20:07:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "../light.h"

void	parse_ambient_light(t_parser_ctx *ctx, char **parts, t_light **light)
{
	if (*light)
		throw_parse_err(ctx, "Multiple ambient lights are not allowed");
	if (!parts[1] || !parts[2])
		throw_parse_err(ctx, "Missing ambient light params");
	*light = ft_calloc(1, sizeof(t_light));
	if (!*light)
		throw_sys_error("trying to allocate ambient light");
	(*light)->type = AMBIENT_LIGHT_ID;
	(*light)->brightness = parse_double(ctx, parts[1]);
	parse_color(ctx, parts[2], &(*light)->color);
	if ((*light)->brightness > 1.0 || (*light)->brightness < 0.0)
		throw_parse_err(ctx, "Invalid brightness param for ambient light");
}

int	get_sky_color(t_light *ambient_light)
{
	t_color	sky_color;

	sky_color.red = (0xD6 / (float)255) * ambient_light->brightness;
	sky_color.green = (0xEA / (float)255) * ambient_light->brightness;
	sky_color.blue = (0xF8 / (float)255) * ambient_light->brightness;
	sky_color.alpha = 1.0;
	return (get_color_value(&sky_color));
}
