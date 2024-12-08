/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/08 18:51:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/figure/figure.h"

void 	handle_figure_rotation(t_vector *orientation, t_vector *factor);

void	handle_figure_event(mlx_key_data_t *keydata, t_figure *figure);
