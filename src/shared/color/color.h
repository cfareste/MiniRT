#ifndef COLOR_H
# define COLOR_H

typedef unsigned char	t_rgb_comp;

typedef struct s_color
{
	t_rgb_comp	red;
	t_rgb_comp	green;
	t_rgb_comp	blue;
	t_rgb_comp	alpha;
}	t_color;

void	set_color(char *params, t_color *color);

#endif