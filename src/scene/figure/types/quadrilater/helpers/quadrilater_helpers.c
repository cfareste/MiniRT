/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:09:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/25 22:12:22 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

void	set_quadrilater_vectors(t_figure *quad)
{
	t_vector	world_axis;

	get_axis(&world_axis, UP);
	if (dot(&quad->qu_attrs->orientation, &world_axis) == 1.0)
		get_axis(&world_axis, BACK);
	else if (dot(&quad->qu_attrs->orientation, &world_axis) == -1.0)
		get_axis(&world_axis, FRONT);
	cross(&quad->qu_attrs->orientation, &world_axis, &quad->qu_attrs->right);
	normalize(&quad->qu_attrs->right);
	cross(&quad->qu_attrs->right, &quad->qu_attrs->orientation,
		&quad->qu_attrs->up);
	normalize(&quad->qu_attrs->up);
}
