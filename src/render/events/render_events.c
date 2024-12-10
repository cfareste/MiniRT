/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:54:55 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/10 02:58:56 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_events.h"
#include "../renderer/renderer_bonus.h"
#include <stdio.h>

static void	create_figure(t_scene *scene, t_camera *camera)
{
	t_point			position;
	t_color			color;
	t_sphere_attrs	sp_attrs;
	t_figure		*new_figure;

	translate_point(&camera->position, &camera->front, camera->focus_dist * 4,
		&position);
	new_color(1.0, 1.0, 1.0, &color);
	sp_attrs.radius = 1.0;
	new_figure = new_sphere(&position, &color, &sp_attrs);
	new_figure->next = scene->figures;
	scene->figures = new_figure;
}

void	render_key_events(mlx_key_data_t *keydata, t_window *window)
{
	if (keydata->action == MLX_PRESS)
	{
		if (keydata->key == MLX_KEY_B)
			window->render.blocked = !window->render.blocked;
		if (window->render.blocked)
			return ;
		if (keydata->key == MLX_KEY_R || keydata->key == MLX_KEY_F5)
			render(window);
		if (keydata->key == MLX_KEY_N)
		{
			create_figure(&window->render.scene, window->render.scene.camera);
			render(window);
		}
		else if (keydata->key >= MLX_KEY_1 && keydata->key <= MLX_KEY_3)
		{
			if (keydata->key == MLX_KEY_1)
				window->render.strategy = RAYTRACING;
			else if (keydata->key == MLX_KEY_2)
				window->render.strategy = PATHTRACING;
			else if (keydata->key == MLX_KEY_3)
				window->render.strategy = NORMAL_MAP;
			render(window);
		}
	}
}
