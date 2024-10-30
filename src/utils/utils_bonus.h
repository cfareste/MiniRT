/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/29 17:13:53 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "render/utils/coordinates/coordinates.h"
#include "utils/size/size.h"
#include <pthread.h>

int		correct_file_extension(char *filename, char *extension);

void	throw_sys_error(char *msg);

char	*get_file_name(char *filename, char *extension);

void	throw_mlx_error(char *msg, const char *mlx_msg);

t_size	get_image_size(mlx_image_t *image, pthread_mutex_t *mutex);

int		is_image_enabled(mlx_image_t *image, pthread_mutex_t *mutex);

void	paint_black_image(mlx_image_t *image, pthread_mutex_t *mutex);
