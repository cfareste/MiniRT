/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_box_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 02:38:44 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene_bonus.h"
#include <math.h>

void	configure_sky_box(t_scene *scene)
{
	if (!scene->settings.sky_box)
		return ;
	scene->settings.sky_box->position = scene->camera->position;
	scene->settings.sky_box->sp_attrs->radius
		= scene->settings.sky_box->bump_map.texture->mlx->width / (M_PI * 2.0);
}
