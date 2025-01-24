/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:21 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "render/utils/coordinates/coordinates_bonus.h"

typedef enum e_pointing
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	FRONT,
	BACK
}	t_pointing;

typedef t_coordinates	t_vector;

void	cross(t_vector *vec1, t_vector *vec2, t_vector *res);

float	dot(t_vector *vec1, t_vector *vec2);

void	multiply_vector_scalar(t_vector *vec, float scalar, t_vector *res);

void	sum_vectors(t_vector *vec1, t_vector *vec2, t_vector *res);

void	get_axes(t_vector *front, t_vector *right, t_vector *up);

void	rotate_vector(t_vector *vec, t_vector *axis, float angle,
			t_vector *rotated);

void	get_vector(t_coordinates *final, t_coordinates *start, t_vector *vec);

void	get_world_axis(t_vector *axis, t_pointing direction);

void	normalize(t_vector *vec);

void	reflect(t_vector *vec, t_vector *normal, t_vector *res);
