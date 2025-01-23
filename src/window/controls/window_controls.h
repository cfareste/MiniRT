/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:18:48 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 11:06:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"

typedef int8_t	t_control;

typedef struct s_controls
{
	int			moving;
	int			moving_figure;
	int			pressed_modifier;
	t_control	move_up;
	t_control	move_right;
	t_control	move_front;
	t_control	view_up;
	t_control	view_right;
	t_control	zoom;
	t_control	focus_dist;
	t_control	defocus;
	t_control	view_front;
}	t_controls;

void	set_controls(mlx_key_data_t *keydata, t_controls *controls);
