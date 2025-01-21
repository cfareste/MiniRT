/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:10:35 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/21 12:52:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

void	parse_emissive(t_parser_ctx *ctx, char *str, t_material *material);
