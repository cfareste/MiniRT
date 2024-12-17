/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:06 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/17 21:43:52 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../helpers/render_helper_bonus.h"
#include "../../utils/thread/thread.h"
#include "renderer_parts.h"

static void	join_parts(t_render_part *parts, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (parts[i].thread)
			pthread_join(parts[i].thread, NULL);
		parts[i].thread = 0;
		i++;
	}
}

void	destroy_parts(t_render_part *parts, int amount)
{
	join_parts(parts, amount);
	free(parts);
}

void	fill_parts(t_render *render, t_size *img_size)
{
	int	i;

	free(render->parts);
	render->parts = ft_calloc(render->parts_amount, sizeof(t_render_part));
	if (!render->parts)
		throw_sys_error("ft_calloc in rendering");
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		render->parts[i].render = render;
		render->parts[i].img_size = img_size;
		render->parts[i].pixels_amount = render->px_amount
			/ render->parts_amount;
		render->parts[i].pixels = render->pixels
			+ (render->parts[i].pixels_amount * i);
		i++;
	}
}

void	prepare_parts(t_render *render, t_size *img_size, uint32_t *seed)
{
	render->parts_amount = 10;
	if (render_get_resize(render))
	{
		fill_pixels(img_size, &render->pixels, &render->px_amount);
		render_set_resize(render, 0);
	}
	shuffle_pixels(render->pixels, render->px_amount, seed);
	init_progressive(&render->progressive, img_size);
	fill_parts(render, img_size);
}

void	render_parts(t_render *render)
{
	int	i;

	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		if (pthread_create(&render->parts[i].thread, NULL,
				(void *(*)(void *)) render_part, render->parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(render->parts, render->parts_amount);
}
