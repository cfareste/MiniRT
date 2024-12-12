/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 12:54:22 by cfidalgo         ###   ########.fr       */
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

void	rotate_figure(t_vector *orientation, t_camera *camera, t_vector *factor)
{
	t_vector	front_projected;

	front_projected = camera->front;
	front_projected.y = 0;
	normalize(&front_projected);
	if (factor->x == 0.0 && factor->y == 0.0 && factor->z == 0.0)
		return ;
	if (factor->x)
		rotate_vector(orientation, &camera->right, factor->x, orientation);
	if (factor->y)
		rotate_by_world_axis(UP, factor->y, orientation);
	if (factor->z)
		rotate_vector(orientation, &front_projected, factor->z, orientation);
	normalize(orientation);
}

static void	translate_figure(t_figure *figure, t_camera *camera,
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
	translate_figure(figure, scene->camera, &translate_factor);
	if (figure->rotate)
		figure->rotate(figure, scene->camera, &rotation_factor);
	if (figure->recalculate)
		figure->recalculate(figure);
}
