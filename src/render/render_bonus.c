/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/17 19:04:20 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helpers/render_helper_bonus.h"
#include "window/helpers/window_helper_bonus.h"
#include "render/ray/helpers/ray_helper.h"
#include "render/utils/thread/thread.h"
#include "render/utils/color/color_operations/color_operations.h"
#include "utils/iterators/iterators.h"
#include "render/strategies/strategies.h"
#include <math.h>

static void	compute_strategy(t_render_part *part, t_ray *ray,
	t_color *sample_color, uint32_t *seed)
{
	if (part->render->strategy == RAYTRACING)
		compute_raytracing(part->render, ray, sample_color, seed);
	else if (part->render->strategy == PATHTRACING)
		compute_pathtracing(part->render, ray, sample_color, seed);
	else if (part->render->strategy == NORMAL_MAP)
		compute_normal_map(&part->render->scene, ray, sample_color);
}

static void	render_prog_pixel(t_render_part *part, t_iterators *iter,
	uint32_t *seed)
{
	t_ray			ray;
	t_color			*sample_color;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	sample_color = part->render->progressive.colors
		+ (iter->i * part->img_size->height) + iter->j;
	set_ray_from_camera(&ray, part->render, iter, seed);
	compute_strategy(part, &ray, sample_color, seed);
	multiply_color_scalar(sample_color,
		1 / (float) (part->i + 1), &pixel_color);
	mlx_put_pixel(part->render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

static void	render_pixel(t_render_part *part, t_iterators *iter,
	uint32_t *seed)
{
	t_ray			ray;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	set_ray_from_camera(&ray, part->render, iter, seed);
	compute_strategy(part, &ray, &pixel_color, seed);
	mlx_put_pixel(part->render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

void	*render_part(t_render_part *part)
{
	uint32_t	seed;
	t_iterators	px_iter;
	int			prog_enabled;

	get_thread_id(&part->thread, &seed);
	prog_enabled = get_async_flag(&part->render->prog_enabled);
	while (!is_render_finished(part->render) && (prog_enabled || part->i < 1)
		&& (part->render->samples == 0 || part->i < part->render->samples))
	{
		part->j = 0;
		while (!is_render_finished(part->render)
			&& part->j < part->pixels_amount)
		{
			px_iter = part->pixels[part->j];
			if (prog_enabled)
				render_prog_pixel(part, &px_iter, &seed);
			else
				render_pixel(part, &px_iter, &seed);
			part->j++;
		}
		// printf("Sample %lu\n", part->i);
		part->i++;
	}
	return (NULL);
}

void	init_render(t_render *render, mlx_t *mlx, t_jobs *jobs)
{
	pthread_mutex_init(&render->mutex, NULL);
	pthread_mutex_init(&render->image_mutex, NULL);
	pthread_mutex_init(&render->resize_mutex, NULL);
	pthread_mutex_init(&render->update_mutex, NULL);
	init_async_flag(&render->cheap, 1);
	init_async_flag(&render->cheap_strategy, RAYTRACING);
	init_async_flag(&render->dis_cheap_once, 0);
	init_async_flag(&render->prog_enabled, 1);
	init_async_flag(&render->blocked, 0);
	render->resize = 1;
	render->jobs = jobs;
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	put_image(render->image, mlx, NULL);
	mlx_set_instance_depth(render->image->instances
		+ render->image->count - 1, 0);
}
