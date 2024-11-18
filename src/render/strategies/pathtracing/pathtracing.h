/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:19:13 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 18:32:19 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/scene.h"

void	compute_pathtracing(t_scene *scene, t_ray *ray, t_color *sample_color,
			uint32_t *seed);
