/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_default_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:00:33 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure_bonus.h"

t_figure	*new_sphere_default(t_point *pos, t_color *color)
{
	t_figure		*sphere;
	t_sphere_attrs	sp_attrs;

	sp_attrs.radius = 1;
	sphere = new_sphere(pos, color, &sp_attrs);
	return (sphere);
}
