/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:48 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 12:23:48 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define FIG_LAST_ATT 2
#define FIG_ATT_LEN 4
#include "parser/parser.h"
#include "../figure.h"

int			try_parse_figure(t_parser_ctx *ctx,
				char **parts, t_figure **figure);

t_figure	*parse_figure(t_parser_ctx *ctx, char **parts, int color_i);