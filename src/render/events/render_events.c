/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:54:55 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 15:59:57 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_events.h"
#include "../renderer/renderer_bonus.h"
#include "render/helpers/render_helper_bonus.h"
#include "scene/selection/helpers/scene_selection_helpers.h"

static void	switch_strategy(t_render *render, t_strategy new)
{
	t_strategy	old;
	int			prog_enabled;

	old = get_async_flag(&render->strategy);
	prog_enabled = get_async_flag(&render->prog_enabled);
	if (prog_enabled)
	{
		set_async_flag(&render->cheap_strategy, old);
		set_async_flag(&render->dis_cheap_once, 1);
		set_async_flag(&render->strategy, new);
	}
	else
		set_async_flag(&render->cheap_strategy, new);
	if (old != new || !prog_enabled)
	{
		set_async_flag(&render->persist_prog, 1);
		set_async_flag(&render->update, 1);
	}
}

static void	strategy_events(mlx_key_data_t *keydata, t_window *win)
{
	t_strategy	new;

	new = keydata->key - MLX_KEY_1;
	if (new >= 0 && new < STRATEGIES_AMOUNT)
		switch_strategy(&win->render, new);
	else if (keydata->key == MLX_KEY_4)
	{
		if (!toggle_async_flag(&win->render.cheap))
			set_async_flag(&win->render.prog_enabled, 1);
	}
	else if (keydata->key == MLX_KEY_5)
		if (!toggle_async_flag(&win->render.prog_enabled))
			set_async_flag(&win->render.cheap, 1);
}

static void	pause_and_play(t_render *render)
{
	if (is_render_alive(render))
		stop_render(render);
	else
	{
		set_async_flag(&render->persist_prog, 1);
		if (get_async_flag(&render->prog_enabled))
			set_async_flag(&render->dis_cheap_once, 1);
		set_async_flag(&render->update, 1);
	}
}

static void	create_new_figure(t_render *render)
{
	stop_render(render);
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
	{
		if (get_async_flag(&win->render.prog_enabled))
			set_async_flag(&win->render.dis_cheap_once, 1);
		set_async_flag(&win->render.resize, 1);
		set_async_flag(&win->render.persist_prog, 0);
		set_async_flag(&win->render.update, 1);
	}
	else if (keydata->key == MLX_KEY_P)
		pause_and_play(&win->render);
	else if (keydata->key == MLX_KEY_N)
		create_new_figure(&win->render);
	else
		strategy_events(keydata, win);
}
