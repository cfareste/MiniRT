/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:31:09 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/utils/color/color_bonus.h"

typedef struct s_pattern
{
	t_color	colors[2];
	double	dimension;
}	t_pattern;

void	parse_pattern(t_parser_ctx *ctx, t_pattern *pattern, char **str);
