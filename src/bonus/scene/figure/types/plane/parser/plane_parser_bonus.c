/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:11:31 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render/utils/vector/parser/vector_parser_bonus.h"
#include "../../../parser/figure_parser_bonus.h"
#include "parser/helpers/parser_helper_bonus.h"

static void	check_parsing(t_parser_ctx *ctx, t_figure *plane)
{
	check_ori_vector_parsing(ctx, &plane->pl_attrs->orientation);
}

t_figure	*parse_plane(t_parser_ctx *ctx, char **parts)
{
	t_figure		*plane;
	t_point			position;
	t_color			color;
	t_plane_attrs	plane_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 1)
		throw_parse_err(ctx, "Missing some plane parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	parse_coordinates(ctx, parts[FIG_LAST_ATT + 1], &plane_attrs.orientation);
	parse_color(ctx, parts[FIG_LAST_ATT + 2], &color);
	plane = new_plane(&position, &color, &plane_attrs);
	set_figure_optionals(ctx, plane, &parts[FIG_LAST_ATT + 3]);
	check_parsing(ctx, plane);
	return (plane);
}
