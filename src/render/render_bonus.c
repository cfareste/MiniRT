/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/11 00:52:01 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helpers/render_helper_bonus.h"
#include "loader/helpers/loader_helper/loader_helper_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/ray/helpers/ray_helper.h"
#include "scene/light/utils/light_utils.h"
#include "scene/light/ambient_light/ambient_light.h"
#include "render/utils/thread/thread.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "render/utils/iterators/iterators.h"
#include "scene/figure/helpers/figure_helpers.h"
#include <math.h>

void	check_collisions(t_scene *scene, t_hit_record *hit_record,
			t_iterators *iterators, uint32_t *seed)
{
	t_ray		ray;
	t_figure	*figure;

	hit_record->distance = FLT_MAX;
	figure = scene->figures;
	set_ray_from_camera(&ray, scene, iterators, seed);
	while (figure)
	{
		if (figure->hit(figure, &ray, &hit_record->distance))
			set_hit_record(hit_record, &ray, figure);
		figure = figure->next;
	}
}

void	process_lighting(t_scene *scene, t_hit_record *hit_record,
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

void	render_pixel(t_render_part *part, t_iterators *iterators,
			uint32_t *seed)
{
	unsigned int	k;
	t_color			pixel_color;
	t_color			sample_color;
	t_hit_record	hit_record;

	k = 0;
	ft_bzero(&pixel_color, sizeof(t_color));
	ft_bzero(&sample_color, sizeof(t_color));
	while (k < part->render->scene.settings.samples)
	{
		ft_bzero(&hit_record, sizeof(t_hit_record));
		check_collisions(&part->render->scene, &hit_record, iterators, seed);
		process_lighting(&part->render->scene, &hit_record, &sample_color);
		k++;
	}
	multiply_color_scalar(&sample_color,
		1 / (float) part->render->scene.settings.samples, &pixel_color);
	mlx_put_pixel(part->render->image, iterators->i, iterators->j,
		get_color_value(&pixel_color));
}

void	*render_part(t_render_part *part)
{
	uint32_t		seed;
	t_iterators		iterators;

	set_viewport(part->render->scene.camera,
		&part->render->scene.camera->viewport, part->img_size);
	get_thread_id(&part->thread, &seed);
	iterators.j = 0;
	while (!is_render_finished(part->render)
		&& iterators.j < part->img_size.height)
	{
		iterators.i = part->min_size.height;
		while (!is_render_finished(part->render)
			&& iterators.i < part->img_size.width)
		{
			render_pixel(part, &iterators, &seed);
			add_loader_progress(&part->render->loader);
			iterators.i += part->render->parts_amount;
		}
		iterators.j++;
	}
	return (NULL);
}

void	init_render(t_render *render, mlx_t *mlx)
{
	pthread_mutex_init(&render->mutex, NULL);
	pthread_mutex_init(&render->image_mutex, NULL);
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	put_image(render->image, mlx, NULL);
	init_loader(&render->loader, mlx);
}
