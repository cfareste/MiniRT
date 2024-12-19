/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:54:55 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/19 22:04:18 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_events.h"
#include "../renderer/renderer_bonus.h"
#include "scene/selection/scene_selection.h"
#include "render/helpers/render_helper_bonus.h"
#include <stdio.h>

static void	strategy_events(mlx_key_data_t *keydata, t_window *win)
{
	if (keydata->key >= MLX_KEY_1 && keydata->key <= MLX_KEY_4)
	{
		if (keydata->key == MLX_KEY_1)
		{
			win->render.strategy = RAYTRACING;
			set_async_flag(&win->render.cheap_strategy, RAYTRACING);
		}
		else if (keydata->key == MLX_KEY_2)
			win->render.strategy = PATHTRACING;
		else if (keydata->key == MLX_KEY_3)
		{
			win->render.strategy = NORMAL_MAP;
			set_async_flag(&win->render.cheap_strategy, NORMAL_MAP);
		}
		else if (keydata->key == MLX_KEY_4)
			return (toggle_async_flag(&win->render.cheap));
		else
			return ;
		set_async_flag(&win->render.dis_cheap_once, 1);
		set_async_flag(&win->render.persist_prog, 1);
		set_async_flag(&win->render.update, 1);
	}
}

void	render_key_events(mlx_key_data_t *keydata, t_window *win)
{
	if (keydata->action == MLX_PRESS)
	{
		if (keydata->key == MLX_KEY_B)
		{
			if (!composer_is_alive(&win->composer))
				toggle_async_flag(&win->render.blocked);
		}
		if (get_async_flag(&win->render.blocked))
			return ;
		else if (keydata->key == MLX_KEY_R || keydata->key == MLX_KEY_F5)
			set_async_flag(&win->render.update, 1);
		else if (keydata->key == MLX_KEY_P)
		{
			stop_render(&win->render);
			set_async_flag(&win->render.persist_prog, 1);
			toggle_async_flag(&win->render.update);
		}
		else if (keydata->key == MLX_KEY_N)
		{
			add_figure(&win->render.scene, win->render.scene.camera);
			set_selection_fig(&win->render.scene, win->render.scene.figures);
			set_async_flag(&win->render.update, 1);
		}
		else
			strategy_events(keydata, win);
	}
}
