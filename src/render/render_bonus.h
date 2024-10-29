/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2024/10/29 17:01:26 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MLX42.h"
#include "loader/loader_bonus.h"
#include "render/scene/scene.h"
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
	pthread_mutex_t	render_mutex;
}	t_render;

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_point			point;
	t_vector		normal;
}	t_hit_record;

void	render_scene(t_render *render, t_scene *scene, t_size size);

void	init_render(t_render *render, mlx_t *mlx);
