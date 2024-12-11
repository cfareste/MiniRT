/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events_helpers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:44:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 00:48:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene.h"

t_figure	*get_next_figure_type(t_figure *figure);

void		handle_figure_movement(mlx_key_data_t *key_data, t_camera *camera,
				t_figure *figure);

void		get_rotation_factor(keys_t key, t_point *factor);
