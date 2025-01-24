/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:58:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector_bonus.h"

void	rotate_x_axis(t_vector *point, double angle);

void	rotate_y_axis(t_vector *point, double angle);

void	rotate_z_axis(t_vector *point, double angle);

void	get_vector_angles(t_vector *vec, double *yaw, double *pitch);
