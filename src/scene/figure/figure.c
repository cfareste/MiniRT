/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 19:23:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figure.h"
#include "utils/utils_bonus.h"

void	free_figures(t_figure *figures)
{
	t_figure	*figure;

	while (figures)
	{
		figure = figures;
		figures = figures->next;
		free(figure->attrs);
		free(figure->type);
		free(figure);
	}
}

void	print_figure(t_figure *figure)
{
	printf("%s (%p): %f, %f, %f | ", figure->type, figure,
		figure->position.x, figure->position.y, figure->position.z);
	figure->print_attrs(figure->attrs);
	printf(" | %f, %f, %f | %p\n",
		figure->color.red, figure->color.green, figure->color.blue,
		figure->bump_map.texture);
}
