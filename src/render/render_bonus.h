/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/04 21:52:09 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "scene/scene.h"
#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"

typedef enum e_strategy
{
	PATHTRACING,
	RAYTRACING,
	NORMAL_MAP
}	t_strategy;

typedef struct s_render
{
	int				blocked;
	t_scene			scene;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	pthread_t		thread;
	int				finished;
	pthread_mutex_t	mutex;
	double			start_time;
	int				parts_amount;
	pthread_mutex_t	trigger;
	unsigned int	samples;
	int				antialiasing;
	unsigned int	max_depth;
	t_strategy		strategy;
	float			soft_shadows_radius;
}	t_render;

typedef struct s_render_part
{
	pthread_t	thread;
	t_size		img_size;
	t_size		min_size;
	t_size		max_size;
	t_render	*render;
}	t_render_part;

void	*render_part(t_render_part *part);

void	init_render(t_render *render, mlx_t *mlx);

void	set_render_defaults(t_render *render);
