/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:00:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 23:49:38 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

t_figure	*new_sphere_default(t_point *pos, t_color *color)
{
	t_figure		*sphere;
	t_sphere_attrs	sp_attrs;

	sp_attrs.radius = 1;
	sphere = new_sphere(pos, color, &sp_attrs);
	return (sphere);
}
