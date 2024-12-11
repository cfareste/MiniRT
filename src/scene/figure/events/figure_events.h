/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 20:58:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene.h"
#include "scene/camera/camera.h"

void		change_figure_material(t_figure *selection);

t_figure	*change_figure_type(t_scene *scene, t_figure *old_figure);

void		handle_figure_movement(t_figure *figure, t_camera *camera,
				t_vector *factor);

void		handle_figure_rotation(t_vector *orientation, t_vector *factor);

void		handle_figure_event(mlx_key_data_t *key_data, t_scene *scene,
				t_figure *figure);
