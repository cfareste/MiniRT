/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:05:16 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 02:33:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"
#include "scene/figure/events/figure_events.h"

void	rotate_plane(t_figure *figure, t_point *factor)
{
	handle_figure_rotation(&figure->pl_attrs->orientation, factor);
}
