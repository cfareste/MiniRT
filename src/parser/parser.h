/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/28 20:39:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_parser_ctx
{
	int		error;
	int		error_code;
	int		line;
	char	*filename;
	char	*error_msg;
}	t_parser_ctx;

void	throw_parse_err(t_parser_ctx *ctx, char *error_msg);

double	parse_double(t_parser_ctx *ctx, char *str);

int		parse_int(t_parser_ctx *ctx, char *str);