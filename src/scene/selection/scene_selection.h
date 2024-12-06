/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:18:14 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 21:34:42 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "window/window.h"

t_figure	*get_selection_fig(t_scene *scene);

void		set_selection_fig(t_scene *scene, t_figure *selection);

void		selection_key_events(mlx_key_data_t *keydata, t_window *window);