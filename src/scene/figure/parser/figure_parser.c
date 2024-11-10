/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:53 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/04 18:19:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "figure_parser.h"
#include "../types/plane/parser/plane_parser.h"
#include "../texture/texture.h"

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

static void	check_parsing(t_parser_ctx *ctx, t_figure *figure)
{
	if (figure->glosiness < 0)
		throw_parse_err(ctx, "Glosiness must be a positive value");
	else if (figure->diffuse < 0 || figure->diffuse > 1)
		throw_parse_err(ctx, "Diffuse Strength must be in range [0, 1]");
	else if (figure->specular < 0 || figure->specular > 1)
		throw_parse_err(ctx, "Specular Strength must be in range [0, 1]");
}

t_figure	*parse_figure(t_parser_ctx *ctx, char **parts, int color_i)
{
	t_figure	*figure;

	figure = ft_calloc(1, sizeof(t_figure));
	if (!figure)
		throw_sys_error("trying to allocate new figure");
	figure->type = ft_strdup(parts[0]);
	parse_coordinates(ctx, parts[1], &figure->position);
	figure->glosiness = parse_double(ctx, parts[2]);
	figure->diffuse = parse_double(ctx, parts[3]);
	figure->specular = parse_double(ctx, parts[4]);
	parse_color(ctx, parts[color_i], &figure->color);
	if (ft_matrix_len(parts + color_i) > 1)
		parse_texture(ctx, &figure->texture, parts + color_i + 1);
	check_parsing(ctx, figure);
	return (figure);
}
