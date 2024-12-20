/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:00 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/06 19:44:38 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "window/window.h"

int		diff_sizes(t_size *a, t_size *b);

void	put_image(mlx_image_t *image, mlx_t *mlx, pthread_mutex_t *mutex);
