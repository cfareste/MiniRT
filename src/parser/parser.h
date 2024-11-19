/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 21:22:55 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "window/textures/textures.h"


typedef struct s_parser_ctx
{
	int			error;
	int			error_code;
	int			line;
	char		*filename;
	char		*error_msg;
	t_textures	*textures;
}	t_parser_ctx;

void	parse(t_window *window, char *filename);
