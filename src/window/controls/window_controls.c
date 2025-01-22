/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:21:06 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/22 18:16:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "window_controls.h"

static int	set_control(int8_t *control, mlx_key_data_t *keydata, keys_t pos,
					keys_t neg)
{
	int8_t	mod;
	int8_t	factor;

	factor = 0;
	mod = 0;
	if (keydata->key == pos)
		factor = 1;
	else if (keydata->key == neg)
		factor = -1;
	else
		return (mod);
	if (keydata->action == MLX_PRESS)
		mod = 1;
	else if (keydata->action == MLX_RELEASE)
		mod = -1;
	factor *= mod;
	*control += factor;
	return (mod);
}

static int	check_modifiers(mlx_key_data_t *keydata, t_controls *controls)
{
	if (keydata->modifier > MLX_SHIFT)
	{
		ft_bzero(controls, sizeof(t_controls));
		controls->pressed_modifier = 1;
		return (0);
	}
	if (controls->pressed_modifier)
	{
		if (keydata->action == MLX_RELEASE)
			controls->pressed_modifier = 0;
		return (0);
	}
	return (1);
}

void	set_controls(mlx_key_data_t *keydata, t_controls *controls)
{
	if (!check_modifiers(keydata, controls))
		return ;
	controls->moving += set_control(&controls->zoom,
			keydata, MLX_KEY_O, MLX_KEY_I);
	controls->moving += set_control(&controls->focus_dist,
			keydata, MLX_KEY_J, MLX_KEY_K);
	controls->moving += set_control(&controls->view_up,
			keydata, MLX_KEY_UP, MLX_KEY_DOWN);
	controls->moving += set_control(&controls->view_right,
			keydata, MLX_KEY_RIGHT, MLX_KEY_LEFT);
	controls->moving += set_control(&controls->move_up,
			keydata, MLX_KEY_SPACE, MLX_KEY_LEFT_SHIFT);
	controls->moving += set_control(&controls->move_front,
			keydata, MLX_KEY_W, MLX_KEY_S);
	controls->moving += set_control(&controls->move_right,
			keydata, MLX_KEY_D, MLX_KEY_A);
	controls->moving += set_control(&controls->view_front,
			keydata, MLX_KEY_X, MLX_KEY_Z);
	controls->moving += set_control(&controls->defocus,
			keydata, MLX_KEY_G, MLX_KEY_H);
}
