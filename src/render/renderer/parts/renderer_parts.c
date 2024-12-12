/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:48:06 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/11 01:13:40 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "../../helpers/render_helper_bonus.h"
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

static void	prepare(t_render *render, t_size img_size, uint32_t *seed)
{
	render->parts_amount = 10;
	if (render_get_resize(render))
	{
		fill_pixels(&img_size, &render->pixels, &render->px_amount);
		render_set_resize(render, 0);
	}
	shuffle_pixels(render->pixels, render->px_amount, seed);
}

void	render_parts(t_render *render, t_size img_size, uint32_t *seed)
{
	int				i;
	t_render_part	*parts;

	prepare(render, img_size, seed);
	parts = ft_calloc(render->parts_amount, sizeof(t_render_part));
	if (!parts)
		throw_sys_error("ft_calloc in rendering");
	i = 0;
	while (!is_render_finished(render) && i < render->parts_amount)
	{
		parts[i].render = render;
		parts[i].img_size = img_size;
		parts[i].pixels_amount = render->px_amount / render->parts_amount;
		parts[i].pixels = render->pixels + (parts[i].pixels_amount * i);
		if (pthread_create(&parts[i].thread, NULL,
				(void *(*)(void *)) render_part, parts + i) == -1)
			throw_sys_error("creating render part thread");
		i++;
	}
	join_parts(parts, render->parts_amount);
	free(parts);
}
