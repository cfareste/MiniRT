/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:42:26 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 21:00:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../window.h"

void	key_hook(mlx_key_data_t keydata, t_window *window);

void	scroll_hook(double xdelta, double ydelta, void *param);

void	resize_hook(int32_t width, int32_t height, t_window *window);

void	mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, t_window *window);
