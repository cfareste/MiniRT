/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:27:05 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/07 16:08:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composer_events.h"
#include "../composer.h"

void	composer_key_events(mlx_key_data_t *keydata, t_window *window)
{
	if (keydata->action == MLX_PRESS && keydata->key == MLX_KEY_S)
	{
		if (keydata->modifier == MLX_SUPERKEY
			|| keydata->modifier == MLX_CONTROL)
			compose(&window->composer);
		else if (keydata->modifier == (MLX_SUPERKEY | MLX_SHIFT)
			|| keydata->modifier == (MLX_CONTROL | MLX_SHIFT))
			compose(&window->composer);
	}
}
