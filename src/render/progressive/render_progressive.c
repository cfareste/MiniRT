/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_progressive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:40:45 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/15 00:11:30 by arcanava         ###   ########.fr       */
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
	uint32_t *seed)
{
	t_ray			ray;
	t_color			*sample_color;
	t_color			pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	sample_color = part->render->progress[part->render->strategy].colors
		+ (iter->i * part->img_height) + iter->j;
	set_ray_from_camera(&ray, part->render, iter, seed);
	render_strategy(part, &ray, sample_color, seed);
	multiply_color_scalar(sample_color,
		1 / (float)(part->i + 1), &pixel_color);
	mlx_put_pixel(part->render->image, iter->i, iter->j,
		get_color_value(&pixel_color));
}

static void	*render_prog_part(t_render_part *part)
{
	uint32_t	seed;
	t_iterators	px_iter;

	get_thread_id(&part->thread, &seed);
	while (is_render_alive(part->render)
		&& (part->render->samples == 0 || part->i < part->render->samples))
	{
		part->j = part->j * (part->j != part->pixels_amount);
		while (is_render_alive(part->render) && part->j < part->pixels_amount)
		{
			px_iter = part->pixels[part->j];
			render_prog_pixel(part, &px_iter, &seed);
			part->j++;
		}
		part->i++;
	}
	part->i -= part->j != part->pixels_amount;
	printf("Part %.2d-> %lu samples\n", part->id, part->i);
	return (NULL);
}

static void	prepare_parts(t_render *render, uint32_t *seed, int persist)
{
	t_size	img_size;

	img_size = get_image_size(render->image, &render->image_mutex);
	if (get_async_flag(&render->resize))
	{
		set_async_flag(&render->resize, 0);
		fill_pixels(img_size, &render->pixels, &render->px_amount);
		restart_progress(render->progress, &img_size, render);
	}
	else if (!persist)
		reset_progress(render->progress, &img_size, render->parts_amount);
	else
		return ;
	shuffle_pixels(render->pixels, render->px_amount, seed);
}

void	render_prog_parts(t_render *render, uint32_t *seed, int persist)
{
	int	i;

	prepare_parts(render, seed, persist);
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		render->parts[i].i = render->progress[render->strategy].iter->i;
		render->parts[i].j = render->progress[render->strategy].iter->j;
		if (pthread_create(&render->parts[i].thread,
				NULL, (void *(*)(void *)) render_prog_part,
			render->parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(render->parts, render->parts_amount,
		render->progress + render->strategy);
}
