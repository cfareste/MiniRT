/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:04:36 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/12 13:05:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/figure/figure.h"

void	rotate_figure(t_vector *vec, t_camera *camera, t_vector *factor);

void	translate_figure(t_figure *figure, t_camera *camera, t_vector *factor);
