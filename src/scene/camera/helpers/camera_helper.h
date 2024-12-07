/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:37 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/06 21:32:34 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../camera.h"

#define YAW_POS 0
#define PITCH_POS 1

void	update_camera_fov(t_camera *camera, int factor);

void	update_camera_pos(t_camera *camera, t_point factor);

void	update_camera_front(t_camera *camera, t_point factor);

void	update_camera_focus_dis(t_camera *camera, double factor);
