/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:30:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 13:04:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "render/strategies/shared/strategies_shared.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "libft.h"

static void	modulate_color(t_figure *selected, t_color *color)
{
	t_color	modulation;

	if (selected->material.type == DIFFUSE)
		new_color(0.6, -0.6, -0.6, &modulation);
	else if (selected->material.type == METALLIC)
		new_color(-0.6, 0.6, -0.6, &modulation);
	else if (selected->material.type == PLASTIC)
		new_color(-0.6, -0.6, 0.6, &modulation);
	else if (selected->material.type == GLASS)
		new_color(0.6, -0.6, 0.6, &modulation);
	else
		new_color(0.6, 0.6, 0.6, &modulation);
	sum_colors(color, &modulation, color);
}

void	compute_normal_map(t_scene *scene, t_ray *ray, t_color *sample_color)
{
	t_hit_record	hit_record;

	ft_bzero(&hit_record, sizeof(t_hit_record));
	check_collisions(scene, ray, &hit_record);
	get_normal_color(sample_color, &hit_record.normal);
	if (scene->selection && scene->selection == hit_record.figure)
		modulate_color(scene->selection, sample_color);
}
