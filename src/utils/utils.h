#ifndef UTILS_H
# define UTILS_H

typedef unsigned char	t_rgb_comp;

typedef struct s_color
{
	t_rgb_comp	red;
	t_rgb_comp	green;
	t_rgb_comp	blue;
	t_rgb_comp	alpha;
}	t_color;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}	t_coordinates;

#endif