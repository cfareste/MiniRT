/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:47:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/20 20:06:32 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/utils/iterators/iterators.h"
#include "../shared/strategies_shared.h"
#include "render/helpers/render_helper_bonus.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "scene/light/utils/light_utils.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "libft.h"

static void	process_lighting(t_render *render, t_hit_record *hit_record,
	t_color *final_color)
{
	t_color	light_color;
	t_color	sample_color;
	t_color	figure_color;

	ft_bzero(&sample_color, sizeof(t_color));
	ft_bzero(&light_color, sizeof(t_color));
	if (!hit_record->figure)
	{
		get_sky_color(render->scene.ambient_light,
			&render->scene.settings.sky_color, &sample_color);
		sum_colors(final_color, &sample_color, final_color);
		return ;
	}
	apply_ambient_lighting(render->scene.ambient_light, &light_color);
	get_figure_color(hit_record->figure, &hit_record->point, &figure_color);
	sample_lights(render, hit_record, PLASTIC, &light_color);
	mix_colors(&light_color, &figure_color, &sample_color);
	sum_colors(final_color, &sample_color, final_color);
}

void	compute_raytracing(t_render *render, t_ray *ray, t_color *sample_color)
{
	t_hit_record	hit_record;

	ft_bzero(&hit_record, sizeof(t_hit_record));
	check_collisions(&render->scene, ray, &hit_record);
	process_lighting(render, &hit_record, sample_color);
}
