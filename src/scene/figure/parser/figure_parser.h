/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:48 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/17 21:09:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define FIG_LAST_ATT 3
#define FIG_ATT_LEN 5
#define OPT_BM "bm"
#define OPT_CD "cd"
#include "parser/parser.h"
#include "../figure.h"

int			try_parse_figure(t_parser_ctx *ctx,
				char **parts, t_figure **figure);

t_figure	*parse_figure(t_parser_ctx *ctx, char **parts, int color_i);
