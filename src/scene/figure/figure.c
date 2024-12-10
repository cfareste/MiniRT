/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:53:16 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figure.h"
#include "utils/utils_bonus.h"
#include "texture/bump_map/bump_map.h"
#include "render/utils/random/random.h"

void	free_figure(t_figure *figure)
{
	free(figure->material.material_attrs);
	free(figure->attrs);
	free(figure->type);
	free(figure);
}

void	free_figures(t_figure *figures)
{
	t_figure	*figure;

	while (figures)
	{
		figure = figures;
		figures = figures->next;
		free_figure(figure);
	}
}

void	print_figure(t_figure *figure)
{
	printf("%s (%p): %f, %f, %f | ", figure->type, figure,
		figure->position.x, figure->position.y, figure->position.z);
	figure->print_attrs(figure->attrs);
	printf(" | %f, %f, %f | ",
		figure->color.red, figure->color.green, figure->color.blue);
	print_texture(&figure->bump_map);
}

t_figure	*new_figure(char *type, t_point *position, t_color *color)
{
	t_figure	*figure;

	figure = ft_calloc(1, sizeof(t_figure));
	if (!figure)
		throw_sys_error("trying to allocate new figure");
	figure->type = ft_strdup(type);
	if (!figure->type)
		throw_sys_error("trying to allocate figure type");
	figure->position = *position;
	figure->color = *color;
	figure->glossiness = 256.0;
	parse_diffuse(&figure->material);
	return (figure);
}
