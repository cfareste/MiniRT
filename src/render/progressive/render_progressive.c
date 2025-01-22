/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:45 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/22 19:17:13 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils_bonus.h"
#include "libft.h"
#include "render_progressive.h"
#include "../strategies/strategies.h"
#include "../ray/helpers/ray_helper.h"
#include "../utils/color/color_operations/color_operations.h"
#include "../utils/thread/thread.h"
#include "../helpers/render_helper_bonus.h"
#include "../progressive/helpers/progressive_helper.h"
#include "../renderer/parts/renderer_parts.h"

void	init_progressive(t_rend_prog *prog, t_size *size)
{
	prog->colors = ft_calloc(size->width * size->height + 1,
			sizeof(t_color));
	if (!prog->colors)
		throw_sys_error("Allocating progressive buffer");
}

void	render_prog_pixel(t_render_part *part, t_iterators *iter,
	uint64_t *seed)
{
	t_ray			ray;
	t_color			*sample_color;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	sample_color = part->render->progress[part->render->curr_strategy]
		.colors + (iter->i * part->img_height) + iter->j;
	set_ray_from_camera(&ray, part->render, iter, seed);
	render_strategy(part->render, &ray, sample_color, seed);
	multiply_color_scalar(sample_color,
		1 / (float)(part->i + 1), &pixel_color);
	mlx_put_pixel(part->render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

static void	*render_prog_part(t_render_part *part)
{
	uint64_t	seed;
	t_iterators	px_iter;

	get_thread_id(&part->thread, &seed);
	while (is_render_alive(part->render)
		&& part->i < part->render->samples)
	{
		if (part->j >= part->pixels_amount)
			part->j = 0;
		while (is_render_alive(part->render) && part->j < part->pixels_amount)
		{
			px_iter = part->pixels[part->j];
			render_prog_pixel(part, &px_iter, &seed);
			part->j++;
		}
		part->i++;
	}
	if (part->j < part->pixels_amount && part->i > 0)
		part->i--;
	printf("Part %.2d-> %lu samples\n", part->id, part->i);
	return (NULL);
}

static void	prepare_parts(t_render_args *args, t_render *render, uint64_t *seed)
{
	t_size	img_size;

	img_size = get_image_size(render->image, &render->image_mutex);
	if (args->resize)
	{
		restart_progress(render->progress, &img_size);
		shuffle_pixels(render->pixels, render->px_amount, seed);
	}
	else if (!args->persist)
	{
		reset_progress(render->progress, &img_size, render->parts_amount);
		shuffle_pixels(render->pixels, render->px_amount, seed);
	}
}

void	render_prog_parts(t_render_args *args, t_render *render, uint64_t *seed)
{
	int	i;

	render->curr_strategy = args->strategy;
	prepare_parts(args, render, seed);
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		render->parts[i].i = render->progress[args->strategy].iter[i].i;
		render->parts[i].j = render->progress[args->strategy].iter[i].j;
		if (pthread_create(&render->parts[i].thread,
				NULL, (void *(*)(void *)) render_prog_part,
			render->parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(render->parts, render->parts_amount,
		render->progress + args->strategy);
}
