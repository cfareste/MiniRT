/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:31:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 20:35:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

int		hit_body_cone(t_figure *cone, t_ray *ray, t_point *center,
			float *distance);

void	calculate_ideal_normal(t_point *point, t_figure *cone,
			float *refsys_angle, t_vector *res);
