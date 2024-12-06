/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 02:38:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/06 02:41:12 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include <math.h>

void	configure_sky_box(t_scene *scene)
{
	if (!scene->settings.sky_box)
		return ;
	scene->settings.sky_box->position = scene->camera->position;
	scene->settings.sky_box->sp_attrs->radius
		= scene->settings.sky_box->bump_map.texture->mlx->height / M_PI;
}
