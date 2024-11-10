/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 01:45:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "loader/loader_bonus.h"
#include "scene/scene.h"
#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

typedef struct s_render
{
	t_scene			scene;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	pthread_t		thread;
	t_loader		loader;
	int				finished;
	pthread_mutex_t	mutex;
	double			start_time;
	int				parts_amount;
	pthread_mutex_t	trigger;
	mlx_t			*mlx;
}	t_render;

typedef struct s_render_part
{
	pthread_t	thread;
	t_size		img_size;
	t_size		min_size;
	t_size		max_size;
	t_render	*render;
}	t_render_part;

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_point			point;
	t_vector		normal;
}	t_hit_record;

void	*render_part(t_render_part *part);

void	init_render(t_render *render, mlx_t *mlx);
