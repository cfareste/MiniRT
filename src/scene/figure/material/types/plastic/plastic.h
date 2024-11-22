/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:41:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 17:22:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PLASTIC_ID "plastic"

#include "parser/parser.h"

typedef struct s_plastic_attrs
{
	float	specular_index;
	float	roughness;
}	t_plastic_attrs;

typedef struct s_material	t_material;

void	parse_plastic(t_parser_ctx *ctx, char **attrs_str,
			t_material *material);
