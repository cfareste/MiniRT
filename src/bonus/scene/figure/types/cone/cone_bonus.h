/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:16 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/23 20:26:46 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define CONE_ID "co"

typedef struct s_cone_attrs
{
	double			radius;
	double			height;
	t_coordinates	orientation;
}	t_cone_attrs;

t_figure	*new_cone(t_point *pos, t_color *color, t_cone_attrs *co_attrs);
