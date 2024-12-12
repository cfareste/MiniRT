/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events_helpers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:44:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 20:32:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene.h"

t_material	get_next_material_type(t_figure *figure);

t_figure	*get_next_figure_type(t_figure *figure);

void		get_translation_factor(keys_t key, t_vector *factor);

void		get_rotation_factor(keys_t key, modifier_key_t mod,
				t_point *factor);
