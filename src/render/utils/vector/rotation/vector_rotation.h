/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:58:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 18:59:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/vector/vector.h"

void	rotate_x_axis(t_vector *point, double angle);

void	rotate_y_axis(t_vector *point, double angle);

void	rotate_z_axis(t_vector *point, double angle);
