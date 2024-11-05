/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/04 20:36:13 by arcanava         ###   ########.fr       */
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
	char				*filename;
	t_bump_map_format	format;
	mlx_texture_t		*texture;
	struct s_bump_map	*next;
}	t_bump_map;

void	parse_texture(t_parser_ctx *ctx, t_bump_map *texture, char **str);
