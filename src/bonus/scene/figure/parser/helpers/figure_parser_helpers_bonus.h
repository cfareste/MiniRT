/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser_helpers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:34:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:05:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

void	push_figure(t_figure **figure, t_figure *new_figure);

void	adjust_glossiness(t_figure *figure);

void	check_figure_parsing(t_parser_ctx *ctx, t_figure *figure);
