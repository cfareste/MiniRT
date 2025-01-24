/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:53 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 12:29:29 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "figure_parser.h"
#include "parser/helpers/parser_helper.h"
#include "scene/figure/parser/helpers/figure_parser_helpers.h"
#include "scene/figure/types/cylinder/parser/cylinder_parser.h"
#include "scene/figure/types/plane/parser/plane_parser.h"
#include "scene/figure/types/sphere/parser/sphere_parser.h"

int	try_parse_figure(t_parser_ctx *ctx, char **parts, t_figure **figure)
{
	t_figure	*new;

	if (ft_strcmp(parts[0], CYLINDER_ID) == EQUAL_STRINGS)
		new = parse_cylinder(ctx, parts);
	else if (ft_strcmp(parts[0], PLANE_ID) == EQUAL_STRINGS)
		new = parse_plane(ctx, parts);
	else if (ft_strcmp(parts[0], SPHERE_ID) == EQUAL_STRINGS)
		new = parse_sphere(ctx, parts);
	else
		return (0);
	push_figure(figure, new);
	return (1);
}
