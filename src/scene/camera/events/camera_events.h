/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:29 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/17 15:06:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "window/window.h"

void	focus_camera_to_selection(t_camera *camera, t_figure *selection,
			t_size img_size);

void	camera_key_events(mlx_key_data_t *keydata, t_window *window);