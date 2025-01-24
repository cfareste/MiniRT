/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer_events_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:27:05 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composer_events_bonus.h"

void	composer_key_events(mlx_key_data_t *keydata, t_window *window)
{
	if (keydata->action == MLX_PRESS && keydata->key == MLX_KEY_S
		&& !get_async_flag(&window->render.blocked))
	{
		if (keydata->modifier == MLX_SUPERKEY
			|| keydata->modifier == MLX_CONTROL)
			compose(&window->composer, MODIFY_EXISTING);
		else if (keydata->modifier == (MLX_SUPERKEY | MLX_SHIFT)
			|| keydata->modifier == (MLX_CONTROL | MLX_SHIFT))
			compose(&window->composer, CREATE_FILE);
	}
}
