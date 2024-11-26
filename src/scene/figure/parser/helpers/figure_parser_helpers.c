/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:35:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 12:28:03 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

void	push_figure(t_figure **figure, t_figure *new_figure)
{
	t_figure	*aux;

	if (!*figure)
		*figure = new_figure;
	else
	{
		aux = *figure;
		while (aux->next)
			aux = aux->next;
		aux->next = new_figure;
	}
}
