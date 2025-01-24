/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrilater_helpers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:57:01 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 19:55:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

float	get_quad_rotated_point(t_vector *quad_normal, t_vector *quad_right,
			t_point *rotated_point);

void	rotate_quadrilater(t_figure *quad, t_camera *camera, t_point *factor);
