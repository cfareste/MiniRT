/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/17 18:55:50 by arcanava         ###   ########.fr       */
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
#include "strategies/strategies.h"

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
	size_t			px_amount;
	unsigned long	samples;
	int				antialiasing;
	unsigned int	max_depth;
	t_strategy		strategy;
	t_strategy		curr_strategy;
	t_async_flag	prev_strategy;
	float			soft_shadows_radius;
	t_async_flag	resize;
	t_async_flag	update;
	t_async_flag	cheap;
	t_async_flag	dis_cheap_once;
	t_async_flag	cheap_strategy;
	t_async_flag	prog_enabled;
	t_async_flag	prev_prog_enabled;
	t_async_flag	reset;
	t_rend_prog		progress[STRATEGIES_AMOUNT];
	t_async_flag	persist_prog;
	t_pixel			*pixels;
	t_render_part	*parts;
	int				parts_amount;
}	t_render;

typedef struct s_render_part
{
	int				id;
	pthread_t		thread;
	t_render		*render;
	t_pixel			*pixels;
	size_t			pixels_amount;
	unsigned int	img_height;
	unsigned long	i;
	unsigned long	j;
}	t_render_part;

void	*render_part(t_render_part *part);

void	init_render(t_render *render, mlx_t *mlx);

void	destroy_render(t_render *render);

void	render_strategy(t_render_part *part, t_ray *ray,
			t_color *sample_color, uint64_t *seed);
