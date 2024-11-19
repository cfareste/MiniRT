/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/19 21:23:19 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "coordinates.h"
#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include "parser/parser.h"
#include "parser/helpers/parser_helper.h"
#include <math.h>

void	parse_coordinates(t_parser_ctx *ctx, char *str,
			t_coordinates *coordinates)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts)
		throw_sys_error("ft_split coordinates");
	if (!parts[0] || !parts[1] || !parts[2])
		throw_parse_err(ctx, "Missing some coordinates param");
	coordinates->x = parse_double(ctx, parts[0]);
	coordinates->y = parse_double(ctx, parts[1]);
	coordinates->z = parse_double(ctx, parts[2]);
	free_matrix(parts);
}
