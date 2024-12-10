/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:48 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/10 02:36:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define FIG_LAST_ATT 1
#define FIG_ATT_LEN 3
#define OPT_BM "bm"
#define OPT_CD "cd"
#define OPT_MAT "mat"
#define OPT_GL "gl"
#include "parser/parser.h"
#include "../figure.h"

int		try_parse_figure(t_parser_ctx *ctx,
			char **parts, t_figure **figure);

void	set_figure_optionals(t_parser_ctx *ctx, t_figure *figure, char **parts);
