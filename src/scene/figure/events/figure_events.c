/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 14:44:41 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/events/helpers/figure_events_helpers.h"
#include "render/utils/reference_system/reference_system.h"
#include "render/utils/vector/rotation/vector_rotation.h"
#include "scene/figure/operations/figure_operations.h"
#include "libft.h"
#include <math.h>

void	change_figure_material(t_figure *selection)
{
	t_material	new_material;

	new_material = get_next_material_type(selection);
	free(selection->material.material_attrs);
	selection->material = new_material;
}

t_figure	*change_figure_type(t_scene *scene, t_figure *old_figure)
{
	t_figure	*new_figure;
	t_figure	*prev_old_figure;

	new_figure = get_next_figure_type(old_figure);
	if (scene->figures == old_figure)
		scene->figures = new_figure;
	prev_old_figure = scene->figures;
	while (prev_old_figure && prev_old_figure != old_figure)
	{
		if (prev_old_figure->next == old_figure)
		{
			prev_old_figure->next = new_figure;
			break ;
		}
		prev_old_figure = prev_old_figure->next;
	}
	new_figure->material = old_figure->material;
	new_figure->pattern = old_figure->pattern;
	new_figure->bump_map = old_figure->bump_map;
	new_figure->glossiness = old_figure->glossiness;
	new_figure->next = old_figure->next;
	free(old_figure->attrs);
	free(old_figure->type);
	free(old_figure);
	return (new_figure);
}
