/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 17:22:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "render/utils/coordinates/coordinates.h"
#include "utils/size/size.h"
#include "window/jobs/jobs.h"
#include <pthread.h>

int		correct_file_extension(char *filename, char *extension);

void	throw_sys_error(char *msg);

void	throw_error(char *msg);

void	throw_err_destroy(char *msg, void (*destroy)(void*),
			void *destroy_param);

char	*get_file_name(char *filename, char *extension);

void	throw_mlx_error(t_jobs *jobs, char *msg, const char *mlx_msg);

t_size	get_image_size(mlx_image_t *image, pthread_mutex_t *mutex);

int		is_image_enabled(mlx_image_t *image, pthread_mutex_t *mutex);

char	*set_file_name(char *filename, char *extension,
			char *path, int version);
