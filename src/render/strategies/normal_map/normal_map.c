/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:30:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:13:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal_map.h"
#include "render/strategies/shared/strategies_shared.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "scene/selection/helpers/scene_selection_helpers.h"

static void	modulate_color(t_figure *selected, t_color *color)
{
	t_color	modulation;

	if (selected->material.type == DIFFUSE)
		new_color(0.5, -0.5, -0.5, &modulation);
	else if (selected->material.type == METALLIC)
		new_color(-0.5, 0.5, -0.5, &modulation);
	else if (selected->material.type == PLASTIC)
		new_color(-0.5, -0.5, 0.5, &modulation);
	else if (selected->material.type == GLASS)
		new_color(0.5, -0.5, 0.5, &modulation);
	else
		new_color(0.6, 0.6, 0.6, &modulation);
	sum_colors(color, &modulation, color);
}

void	compute_normal_map(t_scene *scene, t_ray *ray, t_color *sample_color)
{
	t_hit_record	hit_record;
	t_color			px_color;
	t_figure		*selection;

	selection = get_selection_fig(scene);
	check_collisions(scene, ray, &hit_record);
	get_normal_color(&px_color, &hit_record.normal);
	if (selection && selection == hit_record.figure)
		modulate_color(selection, &px_color);
	sum_colors(&px_color, sample_color, sample_color);
}
