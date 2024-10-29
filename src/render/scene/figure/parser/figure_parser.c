/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:53 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 10:12:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "figure_parser.h"
#include "../types/plane/parser/plane_parser.h"

int	try_parse_figure(t_parser_ctx *ctx, char **parts, t_figure **figure)
{
	t_figure	*new;
	t_figure	*aux;

	if (ft_strcmp(parts[0], CYLINDER_ID) == EQUAL_STRINGS)
		new = parse_cylinder(ctx, parts);
	else if (ft_strcmp(parts[0], PLANE_ID) == EQUAL_STRINGS)
		new = parse_plane(ctx, parts);
	else if (ft_strcmp(parts[0], SPHERE_ID) == EQUAL_STRINGS)
		new = parse_sphere(ctx, parts);
	else if (ft_strcmp(parts[0], CONE_ID) == EQUAL_STRINGS)
		new = parse_cone(ctx, parts);
	else
		return (0);
	if (!*figure)
		*figure = new;
	else
	{
		aux = *figure;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (1);
}

t_figure	*parse_figure(t_parser_ctx *ctx, char *type,
				char *coord_str, char *color_str)
{
	t_figure	*new;

	(void) ctx;
	new = ft_calloc(1, sizeof(t_figure));
	if (!new)
		throw_sys_error("trying to allocate new figure");
	new->type = ft_strdup(type);
	parse_coordinates(ctx, coord_str, &new->position);
	parse_color(ctx, color_str, &new->color);
	return (new);
}
