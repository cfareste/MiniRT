/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:18:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathtracing_bonus.h"
#include "libft.h"
#include "scene/figure/helpers/figure_helpers_bonus.h"
#include "scene/light/ambient_light/ambient_light_bonus.h"
#include "render/strategies/shared/strategies_shared_bonus.h"
#include "render/utils/color/color_operations/color_operations_bonus.h"

static void	get_ambient_light(t_scene *scene, t_ray *ray,
	t_color *energy, t_color *final_color)
{
	t_color	light_color;
	t_color	aux;

	get_sky_color(scene, ray, scene->ambient_light, &light_color);
	mix_colors(energy, &light_color, &aux);
	sum_colors(&aux, final_color, final_color);
}

static void	process_lighting(t_scatter_params *params, t_color *energy,
	t_color *light_color, t_color *final_color)
{
	t_hit_record	*hit_record;
	t_color			bounce_color;
	t_color			figure_color;

	hit_record = &params->hit_record;
	ft_bzero(&bounce_color, sizeof(t_color));
	get_figure_color(hit_record->figure, &hit_record->point, &figure_color);
	if (hit_record->figure->material.type == EMISSIVE)
		multiply_color_scalar(&figure_color,
			hit_record->figure->material.emissive_attrs->intensity,
			&bounce_color);
	mix_colors(&bounce_color, energy, &bounce_color);
	if (hit_record->figure->material.type != PLASTIC
		|| (hit_record->figure->material.type == PLASTIC
			&& params->scatter_type == DIFFUSE))
		mix_colors(light_color, &figure_color, light_color);
	mix_colors(light_color, energy, light_color);
	sum_colors(light_color, &bounce_color, &bounce_color);
	sum_colors(final_color, &bounce_color, final_color);
	mix_colors(energy, &figure_color, energy);
}

static int	missed_ray(t_render *render, t_scatter_params *params,
	t_color *energy, t_color *depth_color)
{
	if (!params->hit_record.figure)
	{
		get_ambient_light(&render->scene, params->ray,
			energy, depth_color);
		return (1);
	}
	return (0);
}

void	compute_pathtracing(t_render *render, t_ray *ray, t_color *sample_color,
	uint64_t *seed)
{
	t_scatter_params	params;
	t_color				energy;
	t_color				depth_color;
	t_color				lighting;
	unsigned int		i;

	i = 0;
	ft_bzero(&depth_color, sizeof(t_color));
	new_color(1.0, 1.0, 1.0, &energy);
	params.ray = ray;
	while (i < render->max_depth)
	{
		ft_bzero(&lighting, sizeof(t_color));
		check_collisions(&render->scene, ray, &params.hit_record);
		if (missed_ray(render, &params, &energy, &depth_color)
			|| !params.hit_record.figure->material.scatter(render,
				&params, &lighting, seed))
			break ;
		process_lighting(&params, &energy, &lighting, &depth_color);
		if (params.hit_record.figure->material.type == EMISSIVE)
			break ;
		i++;
	}
	sum_colors(sample_color, &depth_color, sample_color);
}
