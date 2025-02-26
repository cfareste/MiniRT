/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:43 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 16:07:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "float.h"

void	set_ray(t_ray *ray, t_point *origin, t_vector *direction)
{
	ray->bounds.min = 0.001;
	ray->bounds.max = FLT_MAX;
	ray->origin = *origin;
	ray->direction = *direction;
	normalize(&ray->direction);
}
