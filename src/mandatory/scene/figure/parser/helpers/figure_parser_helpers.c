/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:35:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 10:57:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "parser/helpers/parser_helper.h"

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
