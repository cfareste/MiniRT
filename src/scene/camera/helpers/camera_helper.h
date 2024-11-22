/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:37 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/22 13:04:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../camera.h"

void	update_camera_fov(t_camera *camera, int factor);

void	update_camera_pos(t_camera *camera, t_point factor);

void	update_camera_front(t_camera *camera, t_point factor);

void	update_camera_focus_dis(t_camera *camera, double factor);
