/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:11:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:25:07 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"

t_figure	*parse_box(t_parser_ctx *ctx, char **parts);
