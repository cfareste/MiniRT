/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:18:43 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/utils/vector/vector.h"

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}	t_color;

void	parse_color(t_parser_ctx *ctx, char *params, t_color *color);

void	clamp_color(t_color *color);

int		get_color_value(t_color *color);

void	get_normal_color(t_color *color, t_vector *normal);

void	new_color(float red, float green, float blue, t_color *res);
