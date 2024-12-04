/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:54:55 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/04 22:01:04 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_events.h"
#include "../renderer/renderer_bonus.h"

void	render_key_events(mlx_key_data_t *keydata, t_window *window)
{
	if (keydata->action == MLX_PRESS)
	{
		if (keydata->key == MLX_KEY_B)
			window->render.blocked = !window->render.blocked;
		if (window->render.blocked)
			return ;
		if (keydata->key == MLX_KEY_R || keydata->key == MLX_KEY_F5)
			render(window);
		else if (keydata->key >= MLX_KEY_1 && keydata->key <= MLX_KEY_3)
		{
			if (keydata->key == MLX_KEY_1)
				window->render.strategy = RAYTRACING;
			else if (keydata->key == MLX_KEY_2)
				window->render.strategy = PATHTRACING;
			else if (keydata->key == MLX_KEY_3)
				window->render.strategy = NORMAL_MAP;
			render(window);
		}
	}
}
