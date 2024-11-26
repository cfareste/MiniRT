/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:08:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/26 13:27:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

void	set_box_vectors(t_figure *box)
{
	t_vector	world_axis;

	get_axis(&world_axis, UP);
	if (dot(&box->bo_attrs->orientation, &world_axis) == 1.0)
		get_axis(&world_axis, BACK);
	else if (dot(&box->bo_attrs->orientation, &world_axis) == -1.0)
		get_axis(&world_axis, FRONT);
	cross(&box->bo_attrs->orientation, &world_axis, &box->bo_attrs->right);
	normalize(&box->bo_attrs->right);
	cross(&box->bo_attrs->right, &box->bo_attrs->orientation,
		&box->bo_attrs->up);
	normalize(&box->bo_attrs->up);
}
