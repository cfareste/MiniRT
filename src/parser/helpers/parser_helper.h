/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:15:40 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/20 14:37:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../parser.h"

void	throw_parse_err(t_parser_ctx *ctx, char *error_msg);

double	parse_double(t_parser_ctx *ctx, char *str);

int		parse_int(t_parser_ctx *ctx, char *str);

int		ensure_params_amount(t_parser_ctx *ctx, char **args, int amount);