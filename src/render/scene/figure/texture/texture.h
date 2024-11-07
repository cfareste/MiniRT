/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/07 17:21:37 by cfidalgo         ###   ########.fr       */
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
	mlx_texture_t		*texture;
	xpm_t				*xpm;
}	t_bump_map;

void	parse_texture(t_parser_ctx *ctx, t_bump_map *texture, char **str);

void	print_texture(t_bump_map *texture);
