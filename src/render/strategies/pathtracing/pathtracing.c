/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:18:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/19 21:51:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "render/strategies/shared/strategies_shared.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "libft.h"

static void	process_lighting(t_scene *scene, t_hit_record *hit_record,
	t_color *final_color)
{
	t_color	light_color;
	t_color	bounce_color;
	t_color	figure_color;

	ft_bzero(&bounce_color, sizeof(t_color));
	ft_bzero(&light_color, sizeof(t_color));
	if (!hit_record->figure)
	{
		get_sky_color(scene->ambient_light, &scene->settings.sky_color,
			&light_color);
		mix_colors(final_color, &light_color, final_color);
		return ;
	}
	get_figure_color(hit_record->figure, &hit_record->point, &figure_color);
	sample_lights(scene, hit_record, &light_color);
	sum_colors(&figure_color, &light_color, &bounce_color);
	mix_colors(final_color, &bounce_color, final_color);
}

void	compute_pathtracing(t_scene *scene, t_ray *ray, t_color *sample_color,
	uint32_t *seed)
{
	t_hit_record	hit_record;
	t_color			depth_color;
	unsigned int	i;

	i = 0;
	depth_color.red = 1.0;
	depth_color.green = 1.0;
	depth_color.blue = 1.0;
	while (i < scene->settings.max_depth)
	{
		ft_bzero(&hit_record, sizeof(t_hit_record));
		check_collisions(scene, ray, &hit_record);
		process_lighting(scene, &hit_record, &depth_color);
		if (!hit_record.figure)
			break ;
		hit_record.figure->material.scatter(ray, &hit_record, seed);
		i++;
	}
	sum_colors(sample_color, &depth_color, sample_color);
}
