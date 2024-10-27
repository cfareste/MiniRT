/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:53:41 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:53:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ray.h"
#include "render/scene/camera/camera.h"

void	set_ray_from_camera(t_ray *ray, t_camera *camera, int i, int j);

void	set_shadow_ray(t_ray *shadow_ray, t_point *origin, t_point *light_pos);
