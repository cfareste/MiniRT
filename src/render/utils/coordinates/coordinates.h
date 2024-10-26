#pragma once

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}	t_coordinates;

void	set_coordinates(char *str, t_coordinates *coordinates);
