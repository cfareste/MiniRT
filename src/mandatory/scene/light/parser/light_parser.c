/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:12 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 10:42:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser.h"
#include "scene/light/light.h"
#include "parser/helpers/parser_helper.h"

void	parse_light(t_parser_ctx *ctx, char **parts, t_light **lights)
{
	t_light	*light;

	if (!parts[1] || !parts[2])
		throw_parse_err(ctx, "Missing light params");
	light = new_light(lights);
	light->type = *parts[0];
	parse_coordinates(ctx, parts[1], &light->position);
	light->brightness = parse_double(ctx, parts[2]);
	new_color(1, 1, 1, &light->color);
	if (light->brightness < 0)
		throw_parse_err(ctx, "Light brightness must be a positive value");
}
