/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:08:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 12:19:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/point/point.h"

typedef struct s_figure	t_figure;

typedef struct s_hit_record
{
	t_figure		*figure;
	float			distance;
	t_point			point;
	t_vector		normal;
}	t_hit_record;
