/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:40 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/01 23:58:50 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_helper_bonus.h"
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

	pthread_mutex_lock(&render->mutex);
	finished = render->finished;
	pthread_mutex_unlock(&render->mutex);
	return (finished);
}

void	set_render_finish(t_render *render, int value)
{
	pthread_mutex_lock(&render->mutex);
	render->finished = value;
	pthread_mutex_unlock(&render->mutex);
}

void	check_shadow_hits(t_figure **figure, t_hit_record *hit_record,
			t_ray *shadow_ray)
{
	float	distance;

	distance = FLT_MAX;
	while (*figure)
	{
		if (*figure != hit_record->figure
			&& (*figure)->hit(*figure, shadow_ray, &distance))
			break ;
		*figure = (*figure)->next;
	}
}
