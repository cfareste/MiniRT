/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:39:30 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 13:46:20 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GLASS_ID "glass"

typedef struct s_glass_attrs
{
	float	refractive_index;
	float	transparency;
}	t_glass_attrs;

typedef struct s_material	t_material;

void	parse_glass(t_parser_ctx *ctx, char **attrs, t_material *material);
