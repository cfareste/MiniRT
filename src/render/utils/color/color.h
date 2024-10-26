#pragma once
#include "render/utils/coordinates/coordinates.h"

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
	float	alpha;
}	t_color;

void	set_color(char *params, t_color *color);

int		get_color_value(t_color *color);

void	get_normal_color(t_color *color, t_coordinates *normal);
