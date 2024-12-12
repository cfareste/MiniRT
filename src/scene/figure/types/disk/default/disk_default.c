/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:10:53 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 23:53:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

t_figure	*new_disk_default(t_point *pos, t_color *color)
{
	t_figure		*disk;
	t_disk_attrs	di_attrs;

	di_attrs.orientation = wrap_point(0, 1, 0);
	di_attrs.radius = 1;
	disk = new_disk(pos, color, &di_attrs);
	return (disk);
}
