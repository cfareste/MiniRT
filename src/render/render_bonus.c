/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:24 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/15 13:15:31 by arcanava         ###   ########.fr       */
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

void	render_strategy(t_render_part *part, t_ray *ray,
	t_color *sample_color, uint32_t *seed)
{
	if (part->render->curr_strategy == RAYTRACING)
		compute_raytracing(part->render, ray, sample_color, seed);
	else if (part->render->curr_strategy == PATHTRACING)
		compute_pathtracing(part->render, ray, sample_color, seed);
	else if (part->render->curr_strategy == NORMAL_MAP)
		compute_normal_map(&part->render->scene, ray, sample_color);
}

static void	render_pixel(t_render_part *part, t_iterators *iter,
	uint32_t *seed)
{
	t_ray			ray;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	set_ray_from_camera(&ray, part->render, iter, seed);
	render_strategy(part, &ray, &pixel_color, seed);
	mlx_put_pixel(part->render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

void	*render_part(t_render_part *part)
{
	uint32_t	seed;
	t_iterators	px_iter;

	get_thread_id(&part->thread, &seed);
	part->j = 0;
	while (is_render_alive(part->render) && part->j < part->pixels_amount)
	{
		px_iter = part->pixels[part->j];
		render_pixel(part, &px_iter, &seed);
		part->j++;
	}
	return (NULL);
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
