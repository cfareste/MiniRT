/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:15:59 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinates.h"
#include "libft.h"
#include "utils/utils.h"
#include "parser/helpers/parser_helper.h"

void	parse_coordinates(t_parser_ctx *ctx, char *str,
			t_coordinates *coordinates)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts)
		throw_sys_error("ft_split coordinates");
	if (!parts[0] || !parts[1] || !parts[2])
	{
		ctx->cursor = parts[0];
		throw_parse_err(ctx, "Missing some coordinates param");
	}
	coordinates->x = parse_double(ctx, parts[0]);
	coordinates->y = parse_double(ctx, parts[1]);
	coordinates->z = parse_double(ctx, parts[2]);
	free_matrix(parts);
}

t_coordinates	wrap_coordinates(double x, double y, double z)
{
	t_coordinates	coordinates;

	coordinates.x = x;
	coordinates.y = y;
	coordinates.z = z;
	printf("Wrapped Coordinates: %f,%f,%f\n",
		coordinates.x,
		coordinates.y,
		coordinates.z);
	return (coordinates);
}
