/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/11 00:46:56 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "parser/parser.h"

typedef enum e_bump_map_format
{
	OPENGL,
	DIRECTX
}	t_bump_map_format;

typedef struct s_bump_map
{
	t_bump_map_format	format;
	t_texture			*texture;
}	t_bump_map;

void	parse_texture(t_parser_ctx *ctx, t_bump_map *texture, char **str);

void	print_texture(t_bump_map *texture);
