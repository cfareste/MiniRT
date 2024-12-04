/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:55:08 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/04 21:56:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "window/window.h"
#include "../render_bonus.h"

void	render_key_events(mlx_key_data_t *keydata, t_window *window);
