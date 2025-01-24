/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:48 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define FIG_LAST_ATT 1
#define FIG_ATT_LEN 3
#define OPT_BM "bm"
#define OPT_CD "cd"
#define OPT_MAT "mat"
#define OPT_GL "gl"
#include "../figure_bonus.h"

int		try_parse_figure(t_parser_ctx *ctx,
			char **parts, t_figure **figure);

void	set_figure_optionals(t_parser_ctx *ctx, t_figure *figure, char **parts);
