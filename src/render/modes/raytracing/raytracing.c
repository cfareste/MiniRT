/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:47:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 18:30:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/utils/iterators/iterators.h"
#include "../shared/modes_shared.h"
#include "render/helpers/render_helper_bonus.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "scene/light/utils/light_utils.h"
#include "scene/figure/helpers/figure_helpers.h"
#include "libft.h"

static void	process_lighting(t_scene *scene, t_hit_record *hit_record,
	t_color *final_color)
{
	t_color	light_color;
	t_color	sample_color;
	t_color	figure_color;

	ft_bzero(&sample_color, sizeof(t_color));
	ft_bzero(&light_color, sizeof(t_color));
	if (!hit_record->figure)
	{
		get_sky_color(scene->ambient_light, &scene->settings.sky_color,
			&sample_color);
		sum_colors(final_color, sample_color, final_color);
		return ;
	}
	apply_ambient_lighting(scene->ambient_light, &light_color);
	get_figure_color(hit_record->figure, &hit_record->point, &figure_color);
	check_lights(hit_record, scene, &light_color);
	mix_colors(&light_color, &figure_color, &sample_color);
	sum_colors(final_color, sample_color, final_color);
}

void	compute_raytracing(t_scene *scene, t_ray *ray, t_color *sample_color)
{
	t_hit_record	hit_record;

	ft_bzero(&hit_record, sizeof(t_hit_record));
	check_collisions(scene, ray, &hit_record);
	process_lighting(scene, &hit_record, sample_color);
}
