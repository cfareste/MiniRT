/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:18:14 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/07 00:12:52 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "window/window.h"

t_figure	*get_selection_fig(t_scene *scene);

void		set_selection_fig(t_scene *scene, t_figure *selection);

void		selection_key_events(mlx_key_data_t *keydata, t_window *window);

void		select_figure(t_render *render, double x_pos, double y_pos);
