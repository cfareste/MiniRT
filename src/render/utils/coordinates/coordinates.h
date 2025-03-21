/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 13:46:18 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parser/parser.h"

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}	t_coordinates;

void			parse_coordinates(t_parser_ctx *ctx, char *str,
					t_coordinates *coordinates);

t_coordinates	wrap_coordinates(double x, double y, double z);
