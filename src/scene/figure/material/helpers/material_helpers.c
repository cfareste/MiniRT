/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:21:26 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/21 13:22:49 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/point/point.h"
#include "render/utils/random/random.h"

void	randomize_ray_direction(t_vector *ideal_bounce_direction,
	t_point *hit_point, uint32_t *seed, t_vector *res)
{
	t_point		ray_direction_point;
	t_vector	random_direction;
	t_vector	new_ray_point;

	get_random_point_in_sphere(seed, &random_direction);
	normalize(&random_direction);
	if (dot(&random_direction, ideal_bounce_direction) == -1.0)
	{
		*res = *ideal_bounce_direction;
		return ;
	}
	translate_point(hit_point, ideal_bounce_direction, 1, &ray_direction_point);
	translate_point(&random_direction, &ray_direction_point, 1, &new_ray_point);
	get_vector(&new_ray_point, hit_point, res);
}
