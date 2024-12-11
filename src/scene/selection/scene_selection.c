/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:18:16 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/11 00:54:41 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_selection.h"
#include "render/ray/helpers/ray_helper.h"
#include "scene/figure/events/figure_events.h"
#include "render/renderer/renderer_bonus.h"
#include "scene/figure/events/helpers/figure_events_helpers.h"
#include "libft.h"

t_figure	*get_selection_fig(t_scene *scene)
{
	t_figure	*selection;

	pthread_mutex_lock(&scene->selection_mutex);
	selection = scene->selection;
	pthread_mutex_unlock(&scene->selection_mutex);
	return (selection);
}

void	set_selection_fig(t_scene *scene, t_figure *selection)
{
	pthread_mutex_lock(&scene->selection_mutex);
	scene->selection = selection;
	pthread_mutex_unlock(&scene->selection_mutex);
}

void	delete_selection(t_scene *scene, t_figure *selected)
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
	if (!selection)
		return ;
	if (keydata->action == MLX_PRESS)
	{
		stop_render(&window->render);
		if (keydata->key == MLX_KEY_F)
			set_selection_fig(&window->render.scene, NULL);
		else if (keydata->key == MLX_KEY_BACKSPACE)
		{
			delete_selection(&window->render.scene, selection);
			set_selection_fig(&window->render.scene, NULL);
		}
		else if (keydata->key == MLX_KEY_T)
		{
			selection = change_figure_type(&window->render.scene, selection);
			set_selection_fig(&window->render.scene, selection);
		}
		else
			handle_figure_event(keydata, &window->render.scene, selection);
	}
}

void	select_figure(t_render *render, double x_pos, double y_pos)
{
	t_ray			ray;
	uint32_t		seed;
	t_iterators		pixel;
	t_hit_record	hit_record;

	seed = 0;
	pixel.i = (int) x_pos;
	pixel.j = (int) y_pos;
	ft_bzero(&hit_record, sizeof(t_hit_record));
	set_ray_from_camera(&ray, render, &pixel, &seed);
	check_collisions(&render->scene, &ray, &hit_record);
	set_selection_fig(&render->scene, hit_record.figure);
}
