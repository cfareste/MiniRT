/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 12:44:30 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_helper.h"
#include "render/utils/point/point.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure)
{
	if (hit_record->distance >= ray->bounds.max)
		return ;
	ray->bounds.max = hit_record->distance;
	hit_record->figure = figure;
	translate_point(&ray->origin, &ray->direction, hit_record->distance,
		&hit_record->point);
	figure->normal(figure, &hit_record->point, &hit_record->normal);
}

int	is_render_finished(t_render *render)
{
	int	finished;

	pthread_mutex_lock(&render->render_mutex);
	finished = render->finished;
	pthread_mutex_unlock(&render->render_mutex);
	return (finished);
	return (0);
}

void	set_render_finish(t_render *render, int value)
{
	pthread_mutex_lock(&render->render_mutex);
	render->finished = value;
	pthread_mutex_unlock(&render->render_mutex);
}
