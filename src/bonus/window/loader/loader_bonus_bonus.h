/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_bonus_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:22 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "utils/size/size_bonus.h"
#include "window/jobs/jobs_bonus.h"
#include <pthread.h>

#define BAR_MINI
#define TEXT_FULL
#define MIN_LOADER_MINI_WIDTH 10
#define MAX_LOADER_MINI_WIDTH 400
#define MIN_LOADER_MINI_HEIGHT 2
#define MAX_LOADER_MINI_HEIGHT 25
#define LOADER_POS 45

typedef enum loader_size
{
	LOADER_SIZE_MINI,
	LOADER_SIZE_FULL
}	t_loader_size;

typedef enum loader_mode
{
	BAR,
	TEXT
}	t_loader_mode;

typedef struct s_loader_progress
{
	int				current;
	int				total;
	pthread_mutex_t	mutex;
}	t_progress;

typedef struct s_loader
{
	pthread_t		thread;
	t_progress		progress;
	pthread_mutex_t	img_mutex;
	t_size			size;
	t_loader_size	lsize;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_loader_mode	mode;
	int				alive;
	pthread_mutex_t	alive_mutx;
	t_jobs			*jobs;
	int				resize;
	pthread_mutex_t	resize_mutx;
	t_size			*w_size;
}	t_loader;

void	loader_show(t_loader *loader, t_loader_mode mode, t_loader_size size);

void	loader_hide(t_loader *loader);

void	init_loader(t_loader *loader, t_jobs *jobs, mlx_t *mlx, t_size *w_size);

void	loader_update_size(t_loader *loader);

void	loader_toggle_visibility(t_loader *loader);