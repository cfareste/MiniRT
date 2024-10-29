/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:11:31 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 09:33:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "plane_parser.h"
#include "render/utils/vector/parser/vector_parser.h"
#include "../../../parser/figure_parser.h"
#include "../plane.h"

static void	check_parsing(t_parser_ctx *ctx, t_figure *plane)
{
	check_ori_vector_parsing(ctx, &plane->pl_attrs->orientation);
}

t_figure	*parse_plane(t_parser_ctx *ctx, char **parts)
{
	t_figure	*plane;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_parse_err(ctx, "Missing some plane parameter");
	plane = parse_figure(ctx, parts[0], parts[1], parts[3]);
	plane->pl_attrs = ft_calloc(1, sizeof(t_plane_attrs));
	if (!plane->pl_attrs)
		throw_sys_error("trying to allocate plane attributes");
	parse_coordinates(ctx, parts[2], &plane->pl_attrs->orientation);
	normalize(&plane->pl_attrs->orientation);
	set_plane(plane, &plane->position, plane->pl_attrs);
	check_parsing(ctx, plane);
	return (plane);
}
