/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:31:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 17:54:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

void	parse_pattern(t_parser_ctx *ctx, t_pattern *pattern, char **str)
{
	if (!str[1] || !str[2] || !str[3])
		throw_parse_err(ctx, "Missing parameters for color disruption");
	parse_color(ctx, str[1], pattern->colors);
	parse_color(ctx, str[2], pattern->colors + 1);
	pattern->dimension = parse_double(ctx, str[3]);
}
