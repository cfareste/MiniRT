/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_default_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:13:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"

t_figure	*new_cylinder_default(t_point *pos, t_color *color)
{
	t_figure			*cylinder;
	t_cylinder_attrs	cy_attrs;

	cy_attrs.orientation = wrap_point(0, 1, 0);
	cy_attrs.radius = 1;
	cy_attrs.height = 2;
	cylinder = new_cylinder(pos, color, &cy_attrs);
	return (cylinder);
}
