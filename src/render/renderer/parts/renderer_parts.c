/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:06 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 17:41:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../helpers/render_helper_bonus.h"
#include "../../utils/thread/thread.h"
#include "renderer_parts.h"
#include "../../progressive/helpers/progressive_helper.h"

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

t_render_part	*fill_parts(t_render *render, t_size *img_size)
{
	int				i;
	t_render_part	*parts;

	parts = ft_calloc(render->parts_amount + 1, sizeof(t_render_part));
	if (!parts)
		throw_sys_error("ft_calloc in rendering");
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		parts[i].render = render;
		parts[i].img_size = img_size;
		parts[i].pixels_amount = render->px_amount
			/ render->parts_amount;
		parts[i].pixels = render->pixels
			+ (parts[i].pixels_amount * i);
		i++;
	}
	return (parts);
}

static void	prepare_parts(t_render *render, t_size *img_size,
				uint32_t *seed, int persist)
{
	int	resize;

	resize = render_get_resize(render);
	render->parts_amount = 10;
	if (resize)
	{
		render_set_resize(render, 0);
		fill_pixels(img_size, &render->pixels, &render->px_amount);
		restart_progress(render->progress, img_size, render);
	}
	if (!persist)
	{
		reset_progress(render->progress, img_size, render->parts_amount);
		shuffle_pixels(render->pixels, render->px_amount, seed);
	}
}

void	render_parts(t_render *render, t_size *img_size,
			uint32_t *seed, int persist)
{
	int	i;

	prepare_parts(render, img_size, seed, persist);
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		if (pthread_create(&render->progress[render->strategy].parts[i].thread,
				NULL, (void *(*)(void *)) render_part,
			render->progress[render->strategy].parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(render->progress[render->strategy].parts, render->parts_amount);
}
