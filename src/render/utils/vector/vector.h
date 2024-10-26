#pragma once

#include "render/utils/coordinates/coordinates.h"

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

void	get_vector(t_coordinates *final, t_coordinates *start, t_vector *vec);

void	get_axis(t_vector *axis, t_pointing direction);

void	normalize(t_vector *vec);

void	reflect(t_vector *vec, t_vector *normal, t_vector *res);
