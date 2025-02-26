/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:50:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "render/utils/coordinates/coordinates.h"
#include "utils/size/size.h"
#include "render/utils/color/color.h"
#include <pthread.h>

#define SEP 9

int		correct_file_extension(char *filename, char *extension);

void	throw_sys_error(char *msg);

char	*get_file_name(char *filename, char *extension);

t_size	get_image_size(mlx_image_t *image, pthread_mutex_t *mutex);

int		is_image_enabled(mlx_image_t *image, pthread_mutex_t *mutex);

char	*set_file_name(char *filename, char *extension,
			char *path, int version);

char	*colortoa(t_color *color);

char	*coordtoa(t_coordinates *coords, int precision);

void	join_format_str(char **buffer, char *prefix, char *str, char separator);
