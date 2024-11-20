/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:18:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 15:22:56 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "render/strategies/shared/strategies_shared.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "libft.h"

static void	get_ambient_light(t_light *ambient_light, t_color *sky_color,
	t_color *throughput, t_color *final_color)
{
	t_color	light_color;
	t_color	aux;

	get_sky_color(ambient_light, sky_color, &light_color);
	mix_colors(throughput, &light_color, &aux);
	sum_colors(&aux, final_color, final_color);
}

static void	process_lighting(t_scene *scene, t_hit_record *hit_record,
	t_color *throughput, t_color *final_color)
{
	t_color	light_color;
	t_color	bounce_color;
	t_color	figure_color;

	ft_bzero(&bounce_color, sizeof(t_color));
	ft_bzero(&light_color, sizeof(t_color));
	if (!hit_record->figure)
		return (get_ambient_light(scene->ambient_light,
				&scene->settings.sky_color, throughput, final_color));
	get_figure_color(hit_record->figure, &hit_record->point, &figure_color);
	if (hit_record->figure->material.type == EMISSIVE)
		multiply_color_scalar(&figure_color,
			hit_record->figure->material.emissive_attrs->intensity,
			&bounce_color);
	else
		sample_lights(scene, hit_record, &light_color);
	mix_colors(&bounce_color, throughput, &bounce_color);
	mix_colors(&light_color, &figure_color, &light_color);
	mix_colors(&light_color, throughput, &light_color);
	sum_colors(&light_color, &bounce_color, &bounce_color);
	sum_colors(final_color, &bounce_color, final_color);
	mix_colors(throughput, &figure_color, throughput);
}

void	compute_pathtracing(t_scene *scene, t_ray *ray, t_color *sample_color,
	uint32_t *seed)
{
	t_hit_record	hit_record;
	t_color			throughput;
	t_color			depth_color;
	unsigned int	i;

	i = 0;
	ft_bzero(&depth_color, sizeof(t_color));
	throughput.red = 1.0;
	throughput.green = 1.0;
	throughput.blue = 1.0;
	while (i < scene->settings.max_depth)
	{
		ft_bzero(&hit_record, sizeof(t_hit_record));
		check_collisions(scene, ray, &hit_record);
		process_lighting(scene, &hit_record, &throughput, &depth_color);
		if (!hit_record.figure || hit_record.figure->material.type == EMISSIVE)
			break ;
		hit_record.figure->material.scatter(ray, &hit_record, seed);
		i++;
	}
	sum_colors(sample_color, &depth_color, sample_color);
}
