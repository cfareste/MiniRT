/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_default_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:10:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"

t_figure	*new_disk_default(t_point *pos, t_color *color)
{
	t_figure		*disk;
	t_disk_attrs	di_attrs;

	di_attrs.orientation = wrap_point(0, 1, 0);
	di_attrs.radius = 1;
	disk = new_disk(pos, color, &di_attrs);
	return (disk);
}
