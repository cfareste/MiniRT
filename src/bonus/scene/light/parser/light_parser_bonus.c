/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:12 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser/parser_bonus.h"
#include "scene/light/light_bonus.h"
#include "parser/helpers/parser_helper_bonus.h"

void	parse_light(t_parser_ctx *ctx, char **parts, t_light **lights)
{
	t_light	*light;

	(void) ctx;
	if (!parts[1] || !parts[2] || !parts[3])
		throw_parse_err(ctx, "Missing light params");
	light = new_light(lights);
	light->type = *parts[0];
	parse_coordinates(ctx, parts[1], &light->position);
	light->brightness = parse_double(ctx, parts[2]);
	parse_color(ctx, parts[3], &light->color);
	if (light->brightness < 0)
		throw_parse_err(ctx, "Light brightness must be a positive value");
}
