/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:39:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/19 23:43:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"

void	check_sphere_parsing(t_parser_ctx *ctx, t_figure *sphere)
{
	if (sphere->sp_attrs->radius <= 0)
		throw_parse_err(ctx, "Sphere diameter must be a positive value");
}
