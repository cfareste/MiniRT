/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:43:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 12:48:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define METALLIC_ID "metallic"

#include "parser/parser.h"

typedef struct s_metallic_attrs
{
	float	roughness;
}	t_metallic_attrs;

typedef struct s_material	t_material;

void	parse_metallic(t_parser_ctx *ctx, char *attrs_str,
			t_material *material);
