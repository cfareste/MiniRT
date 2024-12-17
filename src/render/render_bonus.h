/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/17 19:28:47 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "scene/scene.h"
#include "render/utils/vector/vector.h"
#include "render/utils/coordinates/coordinates.h"
#include "renderer/pixels/renderer_pixels.h"
#include "utils/async_flag/async_flag.h"
#include "progressive/render_progressive.h"

typedef enum e_strategy
{
	PATHTRACING,
	RAYTRACING,
	NORMAL_MAP
}	t_strategy;

typedef struct s_render_part	t_render_part;

typedef struct s_render
{
	t_async_flag	blocked;
	t_scene			scene;
	mlx_image_t		*image;
	pthread_mutex_t	image_mutex;
	pthread_t		thread;
	int				finished;
	pthread_mutex_t	mutex;
	double			start_time;
	t_pixel			*pixels;
	size_t			px_amount;
	int				parts_amount;
	pthread_mutex_t	trigger;
	unsigned long	samples;
	int				antialiasing;
	unsigned int	max_depth;
	t_strategy		strategy;
	float			soft_shadows_radius;
	int				resize;
	pthread_mutex_t	resize_mutex;
	int				update;
	pthread_mutex_t	update_mutex;
	t_jobs			*jobs;
	t_async_flag	cheap;
	t_async_flag	dis_cheap_once;
	t_async_flag	cheap_strategy;
	t_async_flag	prog_enabled;
	t_progressive	progressive;
	t_render_part	*parts;
}	t_render;

typedef struct s_render_part
{
	pthread_t		thread;
	t_size			*img_size;
	t_render		*render;
	t_pixel			*pixels;
	size_t			pixels_amount;
	unsigned long	i;
	unsigned long	j;
}	t_render_part;

void	*render_part(t_render_part *part);

void	init_render(t_render *render, mlx_t *mlx, t_jobs *jobs);
