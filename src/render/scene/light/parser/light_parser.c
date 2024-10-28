/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:12 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/28 20:41:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "render/scene/light/light.h"

void	parse_light(t_parser_ctx *ctx, char **parts, t_light **lights)
{
	t_light	*light;

	(void) ctx;
	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing light params");
	light = new_light(lights);
	light->type = *parts[0];
	parse_coordinates(ctx, parts[1], &light->position);
	light->brightness = parse_double(ctx, parts[2]);
	parse_color(ctx, parts[3], &light->color);
	if (light->brightness < 0 || light->brightness > 1.0)
		throw_error("Light brightness must be [0.0,1.0]");
}
