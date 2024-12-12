/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:39:18 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/09 23:29:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"

t_figure	*parse_sphere(t_parser_ctx *ctx, char **parts);
