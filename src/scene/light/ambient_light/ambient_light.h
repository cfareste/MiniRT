/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/05 18:08:16 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parser/parser.h"
#include "../light.h"

void	parse_ambient_light(t_parser_ctx *ctx, char **parts, t_light **light);

void	get_sky_color(t_scene *scene, t_ray *ray, t_light *ambient_light,
			t_color *sky_color);
