/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:35:33 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/parser_bonus.h"

typedef enum e_bump_map_format
{
	OPENGL,
	DIRECTX
}	t_bump_map_format;

typedef struct s_bump_map
{
	t_bump_map_format	format;
	float				width_dim;
	t_texture			*texture;
}	t_bump_map;

void	parse_texture(t_parser_ctx *ctx, t_bump_map *texture, char **str);

void	check_file(t_parser_ctx *ctx, char *path);

void	print_texture(t_bump_map *texture);
