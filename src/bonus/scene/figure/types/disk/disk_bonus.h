/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:07:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define DISK_ID "di"

#include "render/utils/point/point_bonus.h"
#include "render/utils/color/color_bonus.h"

typedef struct s_disk_attrs
{
	double		radius;
	t_vector	orientation;
}	t_disk_attrs;

typedef struct s_figure	t_figure;

t_figure	*new_disk(t_point *pos, t_color *color, t_disk_attrs *disk_attrs);
