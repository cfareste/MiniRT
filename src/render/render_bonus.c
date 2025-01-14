/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/14 17:54:59 by arcanava         ###   ########.fr       */
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
#include "renderer/parts/renderer_parts.h"
#include "utils/utils_bonus.h"
#include "renderer/parts/render_parts_amount.h"
#include "renderer/renderer_bonus.h"
#include <math.h>

// static void	compute_strategy(t_render_part *part, t_ray *ray,
// 	t_color *sample_color, uint32_t *seed)
// {
// 	if (part->render->strategy == RAYTRACING)
// 		compute_raytracing(part->render, ray, sample_color, seed);
// 	else if (part->render->strategy == PATHTRACING)
// 		compute_pathtracing(part->render, ray, sample_color, seed);
// 	else if (part->render->strategy == NORMAL_MAP)
// 		compute_normal_map(&part->render->scene, ray, sample_color);
// }

static void	render_pixel(t_render_part *part, t_iterators *iter,
	uint32_t *seed)
{
	t_ray			ray;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	set_ray_from_camera(&ray, part->render, iter, seed);
	if (part->render->strategy == RAYTRACING)
		compute_raytracing(part->render, &ray, &pixel_color, seed);
	else if (part->render->strategy == PATHTRACING)
		compute_pathtracing(part->render, &ray, &pixel_color, seed);
	else if (part->render->strategy == NORMAL_MAP)
		compute_normal_map(&part->render->scene, &ray, &pixel_color);
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
	while (is_render_alive(part->render) && (prog_enabled || part->i < 1)
		&& (part->render->samples == 0 || part->i < part->render->samples))
	{
		part->j = part->j * (part->j != part->pixels_amount);
		while (is_render_alive(part->render) && part->j < part->pixels_amount)
		{
			px_iter = part->pixels[part->j];
			if (prog_enabled)
				render_prog_pixel(part, &px_iter, &seed);
			else
				render_pixel(part, &px_iter, &seed);
			part->j++;
		}
		part->i++;
	}
	part->i -= part->j != part->pixels_amount;
	printf("Part %.2d-> %lu samples\n", part->id, part->i);
	return (NULL);
}

void	render_prog_pixel(t_render_part *part, t_iterators *iter,
	uint32_t *seed)
{
	t_ray			ray;
	t_color			*sample_color;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	sample_color = part->render->progress[part->render->strategy].colors
		+ (iter->i * part->img_height) + iter->j;
	set_ray_from_camera(&ray, part->render, iter, seed);
	if (part->render->strategy == RAYTRACING)
		compute_raytracing(part->render, &ray, sample_color, seed);
	else if (part->render->strategy == PATHTRACING)
		compute_pathtracing(part->render, &ray, sample_color, seed);
	else if (part->render->strategy == NORMAL_MAP)
		compute_normal_map(&part->render->scene, &ray, sample_color);
	multiply_color_scalar(sample_color,
		1 / (float)(part->i + 1), &pixel_color);
	mlx_put_pixel(part->render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

void	destroy_render(t_render *render)
{
	stop_render(render);
	free(render->parts);
}

void	init_render(t_render *render, mlx_t *mlx)
{
	pthread_mutex_init(&render->mutex, NULL);
	pthread_mutex_init(&render->image_mutex, NULL);
	init_async_flag(&render->cheap, 1);
	init_async_flag(&render->cheap_strategy, RAYTRACING);
	init_async_flag(&render->dis_cheap_once, 0);
	init_async_flag(&render->prog_enabled, 1);
	init_async_flag(&render->blocked, 0);
	init_async_flag(&render->persist_prog, 0);
	init_async_flag(&render->update, 1);
	init_async_flag(&render->resize, 1);
	render->image = mlx_new_image(mlx, mlx->width, mlx->height);
	put_image(render->image, mlx, NULL);
	mlx_set_instance_depth(render->image->instances
		+ render->image->count - 1, 0);
	render->parts_amount = PARTS_AMOUNT;
	fill_pixels(get_image_size(render->image, NULL),
		&render->pixels, &render->px_amount);
	set_parts(render);
}
