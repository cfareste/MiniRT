/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 13:34:24 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parser/parser.h"
#include "../light.h"

void	parse_ambient_light(t_parser_ctx *ctx, char **parts, t_light **light);

void	get_sky_color(t_light *ambient_light, t_color *scene_sky_color,
			t_color *sky_color);
