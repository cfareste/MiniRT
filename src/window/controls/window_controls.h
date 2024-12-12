/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:18:48 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 12:27:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"

typedef struct s_controls
{
	int		moving;
	int8_t	move_up;
	int8_t	move_right;
	int8_t	move_front;
	int8_t	view_up;
	int8_t	view_right;
	int8_t	zoom;
	int8_t	focus_dist;
	int8_t	defocus;
	int8_t	rotate_z;
}	t_controls;

void	set_controls(mlx_key_data_t *keydata, t_controls *controls);