/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:22:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 20:35:20 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/vector/parser/vector_parser.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/figure_parser.h"
#include "libft.h"

static void	check_cone_parsing(t_parser_ctx *ctx, t_figure *cone)
{
	check_ori_vector_parsing(ctx, &cone->co_attrs->orientation);
	if (cone->co_attrs->radius <= 0)
		throw_parse_err(ctx, "Cone diameter must be a positive value");
	else if (cone->co_attrs->height <= 0)
		throw_parse_err(ctx, "Cone height must be a positive value");
}

t_figure	*parse_cone(t_parser_ctx *ctx, char **parts)
{
	t_figure		*cone;
	t_point			position;
	t_color			color;
	t_cone_attrs	co_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 3)
		throw_parse_err(ctx, "Missing some cone parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1], &co_attrs.orientation);
	co_attrs.radius = parse_double(ctx, parts[FIG_LAST_ATT + 2]) / 2.0f;
	co_attrs.height = parse_double(ctx, parts[FIG_LAST_ATT + 3]);
	parse_color(ctx, parts[FIG_LAST_ATT + 4], &color);
	cone = new_cone(&position, &color, &co_attrs);
	set_figure_optionals(ctx, cone, &parts[FIG_LAST_ATT + 5]);
	check_cone_parsing(ctx, cone);
	return (cone);
}
