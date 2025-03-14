/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:18:14 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/15 17:17:39 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "window/window.h"

void	deselect_figure(t_render *render);

void	selection_key_events(mlx_key_data_t *keydata, t_window *window);

void	select_figure(t_render *render, double x_pos, double y_pos);
