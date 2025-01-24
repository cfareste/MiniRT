/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 15:55:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "window/window.h"

int			diff_sizes(t_size *a, t_size *b);

void		put_image(mlx_image_t *image, mlx_t *mlx, pthread_mutex_t *mutex);

t_window	*get_window(t_window *window);