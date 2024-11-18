/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:42:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/18 20:59:09 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_record.h"
#include "scene/figure/figure.h"

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
