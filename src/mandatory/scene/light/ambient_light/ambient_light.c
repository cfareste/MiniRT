/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:32:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "../light.h"
#include "parser/helpers/parser_helper.h"
#include "scene/scene.h"
#include <math.h>

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

void	get_sky_color(t_light *ambient_light, t_color *sky_color)
{
	t_color			scene_sky_color;

	new_color(1.0 / 255.0, 197.0 / 255.0, 253.0 / 255.0, &scene_sky_color);
	multiply_color_scalar(&scene_sky_color, ambient_light->brightness,
		sky_color);
}
