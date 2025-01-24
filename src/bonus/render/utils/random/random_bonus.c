/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:35:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random_bonus.h"
#include <math.h>

uint64_t	get_random(uint64_t *seed)
{
	*seed ^= *seed << 13;
	*seed ^= *seed >> 17;
	*seed ^= *seed << 5;
	return (*seed);
}

float	get_random_float(uint64_t *seed)
{
	*seed ^= *seed << 13;
	*seed ^= *seed >> 17;
	*seed ^= *seed << 5;
	return (*seed / (float) UINT64_MAX);
}

void	get_random_point_in_disk(uint64_t *seed, t_vector *vec)
{
	while (42)
	{
		vec->x = get_random_float(seed) - 0.5;
		vec->y = get_random_float(seed) - 0.5;
		vec->z = 0.0;
		if (sqrt(dot(vec, vec)) < 1.0)
			return ;
	}
}

void	get_random_point_in_square(uint64_t *seed, t_vector *vec)
{
	vec->x = get_random_float(seed) - 0.5;
	vec->y = get_random_float(seed) - 0.5;
}

void	get_random_point_in_sphere(uint64_t *seed, t_point *point)
{
	while (42)
	{
		point->x = (get_random_float(seed) * 2.0) - 1.0;
		point->y = (get_random_float(seed) * 2.0) - 1.0;
		point->z = (get_random_float(seed) * 2.0) - 1.0;
		if (sqrt(dot(point, point)) < 1.0)
			return ;
	}
}
