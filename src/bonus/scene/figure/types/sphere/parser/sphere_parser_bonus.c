/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:39:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/helpers/parser_helper_bonus.h"
#include "scene/figure/parser/figure_parser_bonus.h"
#include "libft.h"

static void	check_sphere_parsing(t_parser_ctx *ctx, t_figure *sphere)
{
	if (sphere->sp_attrs->radius <= 0)
		throw_parse_err(ctx, "Sphere diameter must be a positive value");
}

t_figure	*parse_sphere(t_parser_ctx *ctx, char **parts)
{
	t_figure		*sphere;
	t_point			position;
	t_color			color;
	t_sphere_attrs	sphere_attrs;

	if (ft_matrix_len(parts) < FIG_ATT_LEN + 1)
		throw_parse_err(ctx, "Missing some sphere parameter");
	parse_coordinates(ctx, parts[FIG_LAST_ATT], &position);
	sphere_attrs.radius = parse_double(ctx, parts[FIG_LAST_ATT + 1]) / 2.0;
	parse_color(ctx, parts[FIG_LAST_ATT + 2], &color);
	sphere = new_sphere(&position, &color, &sphere_attrs);
	set_figure_optionals(ctx, sphere, &parts[FIG_LAST_ATT + 3]);
	check_sphere_parsing(ctx, sphere);
	return (sphere);
}
