/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:54:55 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/15 18:13:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_events.h"
#include "../renderer/renderer_bonus.h"
#include "scene/selection/scene_selection.h"
#include "render/helpers/render_helper_bonus.h"
#include "scene/selection/helpers/scene_selection_helpers.h"
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

static void	pause_and_play(t_render *render)
{
	if (is_render_alive(render))
		stop_render(render);
	else
	{
		set_async_flag(&render->persist_prog, 1);
		set_async_flag(&render->dis_cheap_once, 1);
		set_async_flag(&render->update, 1);
	}
}

static void	create_new_figure(t_render *render)
{
	add_figure(&render->scene, render->scene.camera);
	set_selection_fig(&render->scene, render->scene.figures);
	set_async_flag(&render->prev_strategy,
		get_async_flag(&render->cheap_strategy));
	set_async_flag(&render->cheap_strategy, NORMAL_MAP);
	set_async_flag(&render->prev_prog_enabled,
		get_async_flag(&render->prog_enabled));
	set_async_flag(&render->prog_enabled, 0);
	set_async_flag(&render->update, 1);
}

void	render_key_events(mlx_key_data_t *keydata, t_window *win)
{
	if (keydata->action != MLX_PRESS)
		return ;
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
		pause_and_play(&win->render);
	else if (keydata->key == MLX_KEY_N)
		create_new_figure(&win->render);
	else
		strategy_events(keydata, win);
}
