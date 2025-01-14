/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:06 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/14 17:40:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../helpers/render_helper_bonus.h"
#include "../../utils/thread/thread.h"
#include "renderer_parts.h"
#include "../../progressive/helpers/progressive_helper.h"

static void	join_parts(t_render_part *parts, int amount, t_rend_prog *progress)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (parts[i].thread)
			pthread_join(parts[i].thread, NULL);
		parts[i].thread = 0;
		if (progress)
		{
			progress->iter[i].i = parts[i].i;
			progress->iter[i].j = parts[i].j;
		}
		i++;
	}
}

void	update_parts(t_render *render, t_size *img_size)
{
	int	i;

	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		render->parts[i].img_height = img_size->height;
		render->parts[i].pixels_amount = render->px_amount
			/ render->parts_amount;
		render->parts[i].pixels = render->pixels
			+ (render->parts[i].pixels_amount * i);
		i++;
	}
}

void	set_parts(t_render *render)
{
	int				i;

	render->parts = ft_calloc(render->parts_amount, sizeof(t_render_part));
	if (!render->parts)
		throw_sys_error("ft_calloc in rendering");
	i = 0;
	while (i < render->parts_amount)
	{
		render->parts[i].id = i + 1;
		render->parts[i].render = render;
		render->parts[i].img_height = render->image->height;
		render->parts[i].pixels_amount = render->px_amount
			/ render->parts_amount;
		render->parts[i].pixels = render->pixels
			+ (render->parts[i].pixels_amount * i);
		i++;
	}
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
		shuffle_pixels(render->pixels, render->px_amount, seed);
	}
	else if (!persist)
		reset_progress(render->progress, &img_size, render->parts_amount);
}

void	render_parts(t_render *render, uint32_t *seed, int persist)
{
	int	i;

	prepare_parts(render, seed, persist);
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		render->parts[i].i = render->progress[render->strategy].iter->i;
		render->parts[i].j = render->progress[render->strategy].iter->j;
		if (pthread_create(&render->parts[i].thread,
				NULL, (void *(*)(void *)) render_part,
			render->parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(render->parts, render->parts_amount,
		render->progress + render->strategy);
}
