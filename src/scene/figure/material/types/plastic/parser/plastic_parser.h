/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plastic_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:40:42 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:02:07 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/helpers/parser_helper.h"
#include "scene/figure/material/material.h"

void	parse_plastic(t_parser_ctx *ctx, char **attrs, t_material *material);
