/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_selection_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:10:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/15 17:11:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render_bonus.h"

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
