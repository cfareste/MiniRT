/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_default_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:19:28 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"

t_figure	*new_box_default(t_point *pos, t_color *color)
{
	t_figure	*box;
	t_box_attrs	bo_attrs;

	bo_attrs.faces[0].attrs.right = wrap_point(1, 0, 0);
	bo_attrs.faces[0].attrs.up = wrap_point(0, 0, -1);
	bo_attrs.width = 1;
	bo_attrs.height = 1;
	bo_attrs.length = 1;
	box = new_box(pos, color, &bo_attrs);
	return (box);
}
