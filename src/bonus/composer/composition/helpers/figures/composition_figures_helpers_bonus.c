/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_figures_helpers_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:32:27 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "composition_figures_helpers_bonus.h"
#include "libft.h"

static void	fill_glossiness(double glossiness, t_material *material,
	char **buffer)
{
	double	original_glossiness;

	original_glossiness = glossiness;
	if (material->type == METALLIC)
		original_glossiness /= (1.1 - material->metallic_attrs->roughness);
	else if (material->type == PLASTIC)
		original_glossiness /= (1.1 - material->plastic_attrs->roughness);
	if (original_glossiness != 256.0)
		join_format_str(buffer, GLOSSINESS_TITLE,
			ft_dtoa(original_glossiness, 3), SEP);
}

static void	fill_pattern(t_pattern *pattern, char **buffer)
{
	push_str(buffer, PATTERN_TITLE, throw_sys_error, "composing pattern");
	join_format_str(buffer, NULL, colortoa(&pattern->colors[0]), ':');
	join_format_str(buffer, NULL, colortoa(&pattern->colors[1]), ':');
	join_format_str(buffer, NULL, ft_dtoa(pattern->dimension, 8), SEP);
}

static void	fill_bump_map(t_bump_map *bump_map, t_texture *texture,
	char **buffer)
{
	push_str(buffer, BUMP_MAP_TITLE, throw_sys_error, "composing bump map");
	push_str(buffer, texture->path, throw_sys_error, "composing path");
	push_char(buffer, ':', throw_sys_error, "pushing separator");
	join_format_str(buffer, NULL, ft_dtoa(bump_map->width_dim, 8), ':');
	if (bump_map->format != OPENGL)
		push_str(buffer, "directx", throw_sys_error, "pushing texture format");
	else
		push_str(buffer, "opengl", throw_sys_error, "pushing texture format");
}

static int	fill_optional(t_composer *composer, t_figure *figure, char **buffer)
{
	t_material	*material;

	if (!composer_is_alive(composer))
		return (1);
	material = &figure->material;
	if (material->type != DIFFUSE)
		join_format_str(buffer, MATERIAL_TITLE,
			material->compose(material), '\0');
	fill_glossiness(figure->glossiness, &figure->material, buffer);
	if (figure->pattern.dimension)
		fill_pattern(&figure->pattern, buffer);
	if (figure->bump_map.texture)
		fill_bump_map(&figure->bump_map, figure->bump_map.texture, buffer);
	return (0);
}

int	fill_figures(t_composer *composer, t_figure *figures, char **buffer)
{
	t_point		center;
	t_figure	*figure;

	if (!composer_is_alive(composer))
		return (1);
	figure = figures;
	while (figure && composer_is_alive(composer))
	{
		push_str(buffer, figure->type, throw_sys_error, "pushing figure type");
		push_char(buffer, SEP, throw_sys_error, "pushing whitespace");
		center = figure->position;
		if (ft_strcmp(figure->type, CONE_ID) == EQUAL_STRINGS)
			translate_point(&center, &figure->co_attrs->orientation,
				figure->co_attrs->height / 2.0, &center);
		join_format_str(buffer, NULL, coordtoa(&center, 3), SEP);
		join_format_str(buffer, NULL, figure->compose(figure), '\0');
		join_format_str(buffer, NULL, colortoa(&figure->color), SEP);
		if (fill_optional(composer, figure, buffer))
			return (1);
		push_char(buffer, '\n', throw_sys_error, "joining newline with buffer");
		figure = figure->next;
	}
	return (0);
}
