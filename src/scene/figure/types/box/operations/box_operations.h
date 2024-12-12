/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_operations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:16:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 12:05:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "scene/figure/figure.h"

void	rotate_box(t_figure *figure, t_camera *camera, t_point *factor);

void	recalculate_box(t_figure *figure);
