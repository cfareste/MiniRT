/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:08 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 19:37:07 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "window/textures/textures.h"

typedef struct s_window	t_window;

typedef struct s_parser_ctx
{
	int			error;
	int			error_code;
	int			line;
	char		*curr_line;
	char		*cursor;
	char		*filename;
	char		*error_msg;
	t_textures	*textures;
}	t_parser_ctx;

void	parse(t_window *window, char *filename);
