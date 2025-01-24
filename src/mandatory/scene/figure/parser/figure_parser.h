/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:48 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 10:57:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define FIG_LAST_ATT 1
#define FIG_ATT_LEN 3
#define OPT_BM "bm"
#define OPT_CD "cd"
#define OPT_MAT "mat"
#define OPT_GL "gl"
#include "../figure.h"

int		try_parse_figure(t_parser_ctx *ctx,
			char **parts, t_figure **figure);