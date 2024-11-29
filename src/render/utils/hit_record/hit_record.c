/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:42:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/28 23:11:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_record.h"
#include "scene/figure/figure.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure)
{
	ray->bounds.max = hit_record->distance;
	hit_record->figure = figure;
}
