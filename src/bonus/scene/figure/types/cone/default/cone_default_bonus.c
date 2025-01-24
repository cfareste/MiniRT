/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_default_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:15:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"

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
