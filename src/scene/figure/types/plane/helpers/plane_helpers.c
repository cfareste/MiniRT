/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:05:16 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 13:09:05 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/operations/figure_operations.h"

void	rotate_plane(t_figure *figure, t_camera *camera, t_point *factor)
{
	rotate_figure(&figure->pl_attrs->orientation, camera, factor);
}
