/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes_shared.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:39 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 18:30:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/scene.h"

void	set_hit_record(t_hit_record *hit_record, t_ray *ray, t_figure *figure);

void	check_lights(t_hit_record *hit_record, t_scene *scene, t_color *color);

void	check_collisions(t_scene *scene, t_ray *ray, t_hit_record *hit_record);
