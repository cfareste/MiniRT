/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_loader_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:33:22 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/21 19:55:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "utils/size/size.h"
#include <pthread.h>

typedef enum loader_mode
{
	PROGRESS_MODE,
	ANIMATION_MODE,
	MESSAGE_MODE
}	t_loader_mode;

typedef struct s_loader_progress
{
	int	current;
	int	total;
}	t_progress;

typedef struct s_multi_loader
{
	pthread_t		thread;
	t_progress		progress;
	pthread_mutex_t	mutex;
	int				background;
	t_size			size;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_loader_mode	mode;
}	t_multi_loader;

void	loader_show_animation(t_multi_loader *loader, int background,
			t_size size);

void	loader_hide(t_multi_loader *loader);

void	init_multi_loader(t_multi_loader *loader, mlx_t *mlx);