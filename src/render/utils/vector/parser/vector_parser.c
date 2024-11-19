/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:20:13 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/19 21:25:54 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_parser.h"
#include "parser/helpers/parser_helper.h"

void	check_ori_vector_parsing(t_parser_ctx *ctx, t_vector *vector)
{
	if (vector->x > 1.0 || vector->x < -1.0
		|| vector->y > 1.0 || vector->y < -1.0
		|| vector->z > 1.0 || vector->z < -1.0)
		throw_parse_err(ctx, "Orientation vector must be in range [-1.0,1.0]");
}
