/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:08:46 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 23:49:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

t_figure	*new_plane_default(t_point *pos, t_color *color)
{
	t_figure		*plane;
	t_plane_attrs	pl_attrs;

	pl_attrs.orientation = wrap_point(0, 1, 0);
	plane = new_plane(pos, color, &pl_attrs);
	return (plane);
}
