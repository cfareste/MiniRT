/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 22:14:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/events/helpers/figure_events_helpers.h"
#include "render/utils/reference_system/reference_system.h"
#include "render/utils/vector/rotation/vector_rotation.h"
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

void	handle_figure_rotation(t_vector *orientation, t_vector *factor)
{
	if (factor->x == 0.0 && factor->y == 0.0 && factor->z == 0.0)
		return ;
	if (factor->x)
		rotate_x_axis(orientation, factor->x);
	if (factor->y)
		rotate_y_axis(orientation, factor->y);
	if (factor->z)
		rotate_z_axis(orientation, factor->z);
	normalize(orientation);
}

void	handle_figure_translation(t_figure *figure, t_camera *camera,
	t_vector *factor)
{
	t_point		pos;
	t_vector	projected;

	projected = camera->front;
	projected.y = 0.0;
	normalize(&projected);
	pos = figure->position;
	if (factor->x)
		translate_point(&pos, &camera->right, factor->x, &figure->position);
	if (factor->y)
		figure->position.y += factor->y;
	if (factor->z)
		translate_point(&pos, &projected, factor->z, &figure->position);
}

void	handle_figure_event(mlx_key_data_t *key_data, t_scene *scene,
	t_figure *figure)
{
	t_point	translate_factor;
	t_point	rotation_factor;

	get_translation_factor(key_data->key, &translate_factor);
	get_rotation_factor(key_data->key, key_data->modifier, &rotation_factor);
	handle_figure_translation(figure, scene->camera, &translate_factor);
	if (figure->rotate)
		figure->rotate(figure, &rotation_factor);
	if (figure->recalculate)
		figure->recalculate(figure);
}
