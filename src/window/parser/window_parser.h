/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:06:55 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/20 15:25:24 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define WINDOW_PARSE_ID "W"
#define WINDOW_PARSE_HEIGHT_ID "height"
#define WINDOW_PARSE_WIDTH_ID "width"
#include "../window.h"

void	set_window_defaults(t_window *window);

int		try_parse_window_elems(t_parser_ctx *ctx, char **args,
			t_window *window);