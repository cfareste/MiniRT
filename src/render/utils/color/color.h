#pragma once

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
	float	alpha;
}	t_color;

void	set_color(char *params, t_color *color);

int		get_color_value(t_color *color);
