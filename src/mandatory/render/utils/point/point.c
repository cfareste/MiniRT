/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:21:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

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
	return (point);
}
