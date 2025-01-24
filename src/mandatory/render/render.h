/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:24 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:08:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "scene/scene.h"

typedef struct s_render
{
	t_scene			scene;
	mlx_image_t		*image;
	double			start_time;
	size_t			px_amount;
}	t_render;

void	init_render(t_render *render, mlx_t *mlx);

void	*render_parts(t_render *render);
