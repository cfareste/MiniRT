/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:18:46 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 17:44:41 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define RENDER_PARSE_ID "R"
#define SAMPLES_KEY "samples"
#define ANTIALIASING_KEY "antialiasing"
#define MAX_DEPTH_KEY "max_depth"
#define RAYTRACING_KEY "raytracing"
#define NORMAL_MAP_KEY "normal_map"
#define SOFT_SHADOWS_KEY "soft_shadows"
#include "parser/parser.h"
#include "../render_bonus.h"

int		try_parse_render_elems(t_parser_ctx *ctx, char **args,
			t_render *render);

void	set_render_defaults(t_render *render);