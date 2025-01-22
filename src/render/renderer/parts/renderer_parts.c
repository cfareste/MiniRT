/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:06 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/22 14:23:11 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../helpers/render_helper_bonus.h"
#include "../../utils/thread/thread.h"
#include "renderer_parts.h"
#include "../../progressive/helpers/progressive_helper.h"

void	join_parts(t_render_part *parts, int amount, t_rend_prog *progress)
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
		if (i == render->parts_amount - 1)
			render->parts[i].pixels_amount += render->px_amount
				% render->parts_amount;
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
		if (i == render->parts_amount - 1)
			render->parts[i].pixels_amount += render->px_amount
				% render->parts_amount;
		i++;
	}
}

void	render_parts(t_render *render, t_strategy strategy, uint64_t *seed)
{
	int	i;

	shuffle_pixels(render->pixels, render->px_amount, seed);
	render->curr_strategy = strategy;
	i = 0;
	while (is_render_alive(render) && i < render->parts_amount)
	{
		if (pthread_create(&render->parts[i].thread,
				NULL, (void *(*)(void *)) render_part,
			render->parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(render->parts, render->parts_amount, NULL);
}
