/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:08 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 10:32:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
}	t_parser_ctx;

void	parse(t_window *window, char *filename);
