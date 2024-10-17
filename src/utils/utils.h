#ifndef UTILS_H
# define UTILS_H

# include "coordinates.h"

typedef enum e_pointing
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	FRONT,
	BACK
}	t_pointing;

int		correct_file_extension(char *filename, char *extension);

void	throw_error(char *msg);

void	throw_sys_error(char *msg);

void	jump_spaces(char **str);

void	cross(t_coordinates *vec1, t_coordinates *vec2, t_coordinates *res);

float	dot(t_coordinates *vec1, t_coordinates *vec2);

void	get_axis(t_coordinates *axis, t_pointing direction);

void	normalize(t_coordinates *vec);

#endif