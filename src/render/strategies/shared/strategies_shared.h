/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies_shared.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 21:03:57 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/scene.h"

void	check_lights(t_hit_record *hit_record, t_scene *scene, t_color *color);

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record);
