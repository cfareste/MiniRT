/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:54:55 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 21:50:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_events.h"
#include "../renderer/renderer_bonus.h"
#include "scene/selection/scene_selection.h"
#include "render/helpers/render_helper_bonus.h"
#include <stdio.h>

void	render_key_events(mlx_key_data_t *keydata, t_window *win)
{
	if (keydata->action == MLX_PRESS)
	{
		if (keydata->key == MLX_KEY_B)
			win->render.blocked = !win->render.blocked;
		if (win->render.blocked)
			return ;
		if (keydata->key == MLX_KEY_R || keydata->key == MLX_KEY_F5)
			set_render_update(&win->render, 1);
		if (keydata->key == MLX_KEY_N)
		{
			add_figure(&win->render.scene, win->render.scene.camera);
			set_selection_fig(&win->render.scene, win->render.scene.figures);
			set_render_update(&win->render, 1);
		}
		else if (keydata->key >= MLX_KEY_1 && keydata->key <= MLX_KEY_3)
		{
			if (keydata->key == MLX_KEY_1)
				win->render.strategy = RAYTRACING;
			else if (keydata->key == MLX_KEY_2)
				win->render.strategy = PATHTRACING;
			else if (keydata->key == MLX_KEY_3)
				win->render.strategy = NORMAL_MAP;
			set_render_update(&win->render, 1);
		}
	}
}
