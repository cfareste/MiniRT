#pragma once

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}	t_coordinates;

void	set_coordinates(char *str, t_coordinates *coordinates);

void	rotate_reference_system(t_coordinates *normal, t_coordinates *vec,
			t_coordinates *point, t_coordinates *center);
