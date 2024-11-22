/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/22 00:59:20 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/utils/point/point.h"
#include "render/utils/vector/vector.h"
#include <stdio.h>

void	translate_point(t_point *point, t_vector *direction, float scalar,
	t_point *res)
{
	res->x = point->x + (scalar * direction->x);
	res->y = point->y + (scalar * direction->y);
	res->z = point->z + (scalar * direction->z);
}

t_point	wrap_point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	printf("Wrapped point: %f,%f,%f\n",
		point.x,
		point.y,
		point.z);
	return (point);
}
