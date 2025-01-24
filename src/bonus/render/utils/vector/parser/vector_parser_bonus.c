/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:20:13 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_parser_bonus.h"
#include "parser/helpers/parser_helper_bonus.h"

void	check_ori_vector_parsing(t_parser_ctx *ctx, t_vector *vector)
{
	if (vector->x == 0.0 && vector->y == 0.0 && vector->z == 0.0)
		throw_parse_err(ctx, "Orientation vector must point somewhere");
}
