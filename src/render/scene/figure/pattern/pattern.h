/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:31:09 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 17:38:17 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "render/utils/color/color.h"

typedef struct s_pattern
{
	t_color	colors[2];
	double	dimension;
}	t_pattern;

void	parse_pattern(t_parser_ctx *ctx, t_pattern *pattern, char **str);
