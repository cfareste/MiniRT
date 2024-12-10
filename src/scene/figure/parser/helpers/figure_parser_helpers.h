/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser_helpers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:34:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/09 22:46:56 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"

void	push_figure(t_figure **figure, t_figure *new_figure);

void	adjust_glossiness(t_figure *figure);

void	check_figure_parsing(t_parser_ctx *ctx, t_figure *figure);
