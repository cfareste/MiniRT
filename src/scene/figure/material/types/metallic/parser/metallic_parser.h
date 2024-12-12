/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:50:32 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:01:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

void	parse_metallic(t_parser_ctx *ctx, char *str, t_material *material);
