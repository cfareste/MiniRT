/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events_helpers_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:44:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene_bonus.h"

t_material	get_next_material_type(t_figure *figure);

t_figure	*get_next_figure_type(t_figure *figure);

void		get_translation_factor(keys_t key, t_vector *factor);

void		get_rotation_factor(keys_t key, modifier_key_t mod,
				t_point *factor);
