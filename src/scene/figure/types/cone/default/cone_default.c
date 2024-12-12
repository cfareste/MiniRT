/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:15:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 23:50:32 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

t_figure	*new_cone_default(t_point *pos, t_color *color)
{
	t_figure		*cone;
	t_cone_attrs	co_attrs;

	co_attrs.orientation = wrap_point(0, -1, 0);
	co_attrs.radius = 1;
	co_attrs.height = 2;
	cone = new_cone(pos, color, &co_attrs);
	return (cone);
}
