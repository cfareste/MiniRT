/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 12:29:15 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figure.h"
#include "utils/utils.h"
#include <math.h>

void	free_figure(t_figure *figure)
{
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
	return (figure);
}
