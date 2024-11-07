/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "parser/parser.h"
#include "render/utils/color/color_operations/color_operations.h"
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
		throw_parse_err(ctx,
			"Brightness param for ambient light must be in range [0.0,1.0]");
}

void	get_sky_color(t_light *ambient_light, t_color *scene_sky_color,
			t_color *sky_color)
{
	multiply_color_scalar(scene_sky_color, ambient_light->brightness,
		sky_color);
	sky_color->alpha = 1.0;
}
