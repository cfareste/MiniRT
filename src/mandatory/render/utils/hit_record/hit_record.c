/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:42:29 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 16:20:32 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_record.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure)
{
	ray->bounds.max = hit_record->distance;
	hit_record->figure = figure;
}
