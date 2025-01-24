/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:47:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:22:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "../shared/strategies_shared.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "scene/light/utils/light_utils.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "libft.h"

static void	process_lighting(t_sample_lights_params *params,
	t_hit_record *hit_record, t_color *final_color)
{
	t_color					light_color;
	t_color					sample_color;
	t_color					figure_color;

	ft_bzero(&sample_color, sizeof(t_color));
	ft_bzero(&light_color, sizeof(t_color));
	if (!hit_record->figure)
	{
		get_sky_color(params->render->scene.ambient_light, &sample_color);
		sum_colors(final_color, &sample_color, final_color);
		return ;
	}
	apply_ambient_lighting(params->render->scene.ambient_light, &light_color);
	get_figure_color(hit_record->figure, &figure_color);
	sample_lights(params, hit_record, &light_color);
	mix_colors(&light_color, &figure_color, &sample_color);
	sum_colors(final_color, &sample_color, final_color);
}

void	compute_raytracing(t_render *render, t_ray *ray, t_color *sample_color)
{
	t_hit_record			hit_record;
	t_sample_lights_params	params;

	params.render = render;
	check_collisions(&render->scene, ray, &hit_record);
	process_lighting(&params, &hit_record, sample_color);
}
