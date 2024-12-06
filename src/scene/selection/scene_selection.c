/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:18:16 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 22:16:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_selection.h"

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

void	selection_key_events(mlx_key_data_t *keydata, t_window *window)
{
	t_figure	*selection;

	selection = get_selection_fig(&window->render.scene);
	if (!selection)
		return ;
	if (keydata->action == MLX_PRESS && keydata->key == MLX_KEY_P)
		set_selection_fig(&window->render.scene, NULL);
}
