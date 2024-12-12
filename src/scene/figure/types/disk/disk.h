/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:07:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:32:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define DISK_ID "di"

#include "render/utils/point/point.h"
#include "render/utils/color/color.h"

typedef struct s_disk_attrs
{
	double		radius;
	t_vector	orientation;
}	t_disk_attrs;

typedef struct s_figure	t_figure;

t_figure	*new_disk(t_point *pos, t_color *color, t_disk_attrs *disk_attrs);
