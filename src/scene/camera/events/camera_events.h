/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 15:44:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "window/window.h"

void	focus_camera_to_selection(t_camera *camera, t_figure *selection);

void	camera_key_events(mlx_key_data_t *keydata, t_window *window);