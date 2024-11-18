/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:08:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 20:58:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/ray/ray.h"

typedef struct s_figure	t_figure;

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_point			point;
	t_vector		normal;
}	t_hit_record;

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);
