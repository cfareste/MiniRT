/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:34:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 12:48:55 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define EMISSIVE_ID "emissive"

#include "parser/parser.h"

typedef struct s_emissive_attrs
{
	float	intensity;
}	t_emissive_attrs;

typedef struct s_material	t_material;

void	parse_emissive(t_parser_ctx *ctx, char *attrs_str, t_material *material);
