/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:53 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/28 15:25:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "figure_parser.h"
#include "../types/plane/parser/plane_parser.h"
#include "../texture/bump_map/bump_map.h"
#include "scene/figure/material/material.h"
#include "parser/helpers/parser_helper.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "scene/figure/parser/helpers/figure_parser_helpers.h"

int	try_parse_figure(t_parser_ctx *ctx, char **parts, t_figure **figure)
{
	t_figure	*new;

	if (ft_strcmp(parts[0], CYLINDER_ID) == EQUAL_STRINGS)
		new = parse_cylinder(ctx, parts);
	else if (ft_strcmp(parts[0], PLANE_ID) == EQUAL_STRINGS)
		new = parse_plane(ctx, parts);
	else if (ft_strcmp(parts[0], SPHERE_ID) == EQUAL_STRINGS)
		new = parse_sphere(ctx, parts);
	else if (ft_strcmp(parts[0], CONE_ID) == EQUAL_STRINGS)
		new = parse_cone(ctx, parts);
	else if (ft_strcmp(parts[0], DISK_ID) == EQUAL_STRINGS)
		new = parse_disk(ctx, parts);
	else if (ft_strcmp(parts[0], QUAD_ID) == EQUAL_STRINGS)
		new = parse_quadrilater(ctx, parts);
	else if (ft_strcmp(parts[0], BOX_ID) == EQUAL_STRINGS)
		new = parse_box(ctx, parts);
	else
		return (0);
	push_figure(figure, new);
	return (1);
}

static void	parse_glossiness(t_parser_ctx *ctx, t_figure *figure, char *str)
{
	if (!str)
		throw_parse_err(ctx, "Missing glossiness value");
	figure->glossiness = parse_double(ctx, str);
}

static void	parse_material(t_parser_ctx *ctx, char **parts,
	t_material *material)
{
	if (!parts[0])
		throw_parse_err(ctx, "Missing material type");
	else if (ft_strcmp(parts[0], DIFFUSE_ID) == EQUAL_STRINGS)
		parse_diffuse(material);
	else if (ft_strcmp(parts[0], METALLIC_ID) == EQUAL_STRINGS)
		parse_metallic(ctx, parts[1], material);
	else if (ft_strcmp(parts[0], PLASTIC_ID) == EQUAL_STRINGS)
		parse_plastic(ctx, parts + 1, material);
	else if (ft_strcmp(parts[0], GLASS_ID) == EQUAL_STRINGS)
		parse_glass(ctx, parts + 1, material);
	else if (ft_strcmp(parts[0], EMISSIVE_ID) == EQUAL_STRINGS)
		parse_emissive(ctx, parts[1], material);
	else
		throw_parse_err(ctx, safe_ft_strjoin(
				"Unknown material type: ", parts[0], throw_sys_error, "error"));
}

static void	parse_optionals(char **params, int i, t_figure *figure,
				t_parser_ctx *ctx)
{
	char	**sub_params;

	while (params && params[i])
	{
		sub_params = safe_ft_split(params[i], ':',
				throw_sys_error, "error parsing figure optional params");
		if (!sub_params[0])
			(void) NULL;
		else if (ft_strcmp(sub_params[0], OPT_BM) == EQUAL_STRINGS)
			parse_texture(ctx, &figure->bump_map, sub_params);
		else if (ft_strcmp(sub_params[0], OPT_CD) == EQUAL_STRINGS)
			parse_pattern(ctx, &figure->pattern, sub_params);
		else if (ft_strcmp(sub_params[0], OPT_MAT) == EQUAL_STRINGS)
			parse_material(ctx, sub_params + 1, &figure->material);
		else if (ft_strcmp(sub_params[0], OPT_GL) == EQUAL_STRINGS)
			parse_glossiness(ctx, figure, sub_params[1]);
		else
			throw_parse_err(ctx, safe_ft_strjoin(
					"Unknown figure optional param identifier: ", sub_params[0],
					throw_sys_error, "error"));
		free_matrix(sub_params);
		i++;
	}
}

t_figure	*parse_figure(t_parser_ctx *ctx, char **parts, int color_i)
{
	t_figure	*figure;

	figure = ft_calloc(1, sizeof(t_figure));
	if (!figure)
		throw_sys_error("trying to allocate new figure");
	figure->type = ft_strdup(parts[0]);
	set_figure_defaults(figure);
	parse_coordinates(ctx, parts[1], &figure->position);
	parse_color(ctx, parts[color_i], &figure->color);
	parse_optionals(parts, color_i + 1, figure, ctx);
	adjust_glossiness(figure);
	check_figure_parsing(ctx, figure);
	return (figure);
}
