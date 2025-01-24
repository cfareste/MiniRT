/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parser/parser_bonus.h"
#include "../light_bonus.h"

void	parse_ambient_light(t_parser_ctx *ctx, char **parts, t_light **light);

void	get_sky_color(t_scene *scene, t_ray *ray, t_light *ambient_light,
			t_color *sky_color);
