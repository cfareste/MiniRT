/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:20:13 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/02 20:07:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_ori_vector_parsing(t_parser_ctx *ctx, t_vector *vector)
{
	if (vector->x == 0.0 && vector->y == 0.0 && vector->z == 0.0)
		throw_parse_err(ctx, "Orientation vector must point somewhere");
}
