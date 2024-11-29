/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parser_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:35:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/28 15:31:49 by cfidalgo         ###   ########.fr       */
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

void	set_figure_defaults(t_figure *figure)
{
	figure->glossiness = 256.0;
	parse_diffuse(&figure->material);
}

void	adjust_glossiness(t_figure *figure)
{
	if (figure->material.type == METALLIC)
		figure->glossiness *= 1.1 - figure->material.metallic_attrs->roughness;
	else if (figure->material.type == PLASTIC)
		figure->glossiness *= 1.1 - figure->material.plastic_attrs->roughness;
}

void	check_figure_parsing(t_parser_ctx *ctx, t_figure *figure)
{
	if (figure->glossiness <= 0)
		throw_parse_err(ctx, "Glossiness must be a positive value");
}
