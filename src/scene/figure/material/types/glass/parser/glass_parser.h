/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:01:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:05:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

void	parse_glass(t_parser_ctx *ctx, char **parts, t_material *material);
