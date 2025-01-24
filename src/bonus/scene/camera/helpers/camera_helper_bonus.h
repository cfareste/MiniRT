/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:37 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../camera_bonus.h"

void	update_camera_fov(t_camera *camera, int factor);

void	update_camera_pos(t_camera *camera, t_point factor);

void	update_camera_front(t_camera *camera, t_point factor);

void	update_camera_focus_dis(t_camera *camera, double factor);

void	update_camera_defocus_rad(t_camera *camera, double factor);
