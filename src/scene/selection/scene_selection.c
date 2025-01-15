/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:18:16 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/15 18:12:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_selection.h"
#include "render/ray/helpers/ray_helper.h"
#include "scene/figure/events/figure_events.h"
#include "render/renderer/renderer_bonus.h"
#include "scene/figure/events/helpers/figure_events_helpers.h"
#include "scene/camera/events/camera_events.h"
#include "libft.h"
#include "render/helpers/render_helper_bonus.h"
#include "scene/selection/helpers/scene_selection_helpers.h"

void	deselect_figure(t_render *render)
{
	set_async_flag(&render->cheap_strategy,
		get_async_flag(&render->prev_strategy));
	set_selection_fig(&render->scene, NULL);
	set_async_flag(&render->prog_enabled,
		get_async_flag(&render->prev_prog_enabled));
}

void	select_figure(t_render *render, double x_pos, double y_pos)
{
	t_ray			ray;
	uint32_t		seed;
	t_iterators		pixel;
	t_hit_record	hit_record;

	if (get_async_flag(&render->blocked))
		return ;
	seed = 0;
	pixel.i = (int) x_pos;
	pixel.j = (int) y_pos;
	set_ray_from_camera(&ray, render, &pixel, &seed);
	check_collisions(&render->scene, &ray, &hit_record);
	set_selection_fig(&render->scene, hit_record.figure);
	set_async_flag(&render->prev_strategy,
		get_async_flag(&render->cheap_strategy));
	set_async_flag(&render->cheap_strategy, NORMAL_MAP);
	set_async_flag(&render->prev_prog_enabled,
		get_async_flag(&render->prog_enabled));
	set_async_flag(&render->prog_enabled, 0);
}

static void	delete_selection(t_scene *scene, t_figure *selected)
{
	t_figure	*figures;
	t_figure	*prev;

	if (scene->figures == selected)
	{
		scene->figures = scene->figures->next;
		return (free_figure(selected));
	}
	prev = scene->figures;
	figures = scene->figures->next;
	while (figures)
	{
		if (figures == selected)
		{
			prev->next = figures->next;
			free_figure(selected);
			break ;
		}
		prev = prev->next;
		figures = figures->next;
	}
}

void	selection_key_events(mlx_key_data_t *keydata, t_window *window)
{
	t_figure	*selection;

	selection = get_selection_fig(&window->render.scene);
	if (!selection || keydata->action != MLX_PRESS
		|| (keydata->key != MLX_KEY_F && keydata->key != MLX_KEY_T
			&& keydata->key != MLX_KEY_M && keydata->key != MLX_KEY_BACKSPACE
			&& keydata->key != MLX_KEY_ENTER))
		return ;
	stop_render(&window->render);
	if (keydata->key == MLX_KEY_F)
		focus_camera_to_selection(window->render.scene.camera, selection);
	else if (keydata->key == MLX_KEY_BACKSPACE)
	{
		delete_selection(&window->render.scene, selection);
		set_selection_fig(&window->render.scene, NULL);
	}
	else if (keydata->key == MLX_KEY_T)
		set_selection_fig(&window->render.scene,
			change_figure_type(&window->render.scene, selection));
	else if (keydata->key == MLX_KEY_M)
		change_figure_material(selection);
	else if (keydata->key == MLX_KEY_ENTER)
		deselect_figure(&window->render);
	set_async_flag(&window->render.update, 1);
}
