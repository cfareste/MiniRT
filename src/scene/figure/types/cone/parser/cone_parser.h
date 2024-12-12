/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:28:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:19:16 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/parser.h"
#include "scene/figure/figure.h"

t_figure	*parse_cone(t_parser_ctx *ctx, char **parts);
