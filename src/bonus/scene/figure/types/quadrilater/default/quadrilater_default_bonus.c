/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_default_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:03:16 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"

t_figure	*new_quadrilater_default(t_point *pos, t_color *color)
{
	t_figure			*quad;
	t_quadrilater_attrs	qu_attrs;

	qu_attrs.right = wrap_point(1, 0, 0);
	qu_attrs.up = wrap_point(0, 0, -1);
	qu_attrs.width = 1;
	qu_attrs.height = 1;
	quad = new_quadrilater(pos, color, &qu_attrs);
	return (quad);
}
