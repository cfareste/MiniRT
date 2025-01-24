/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:51 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene_bonus.h"
#include "renderer/pixels/renderer_pixels_bonus.h"
#include "utils/async_flag/async_flag_bonus.h"
#include "progressive/render_progressive_bonus.h"
#include "strategies/strategies_bonus.h"

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
	t_async_flag	strategy;
	t_strategy		curr_strategy;
	t_async_flag	prev_strategy;
	float			soft_shadows_radius;
	t_async_flag	resize;
	int				prog_resize;
	t_async_flag	update;
	t_async_flag	cheap;
	t_async_flag	dis_cheap_once;
	t_async_flag	cheap_strategy;
	t_async_flag	prog_enabled;
	t_async_flag	prev_prog_enabled;
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

void	render_strategy(t_render *render, t_ray *ray,
			t_color *sample_color, uint64_t *seed);
