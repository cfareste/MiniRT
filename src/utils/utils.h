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

int		correct_file_extension(char *filename, char *extension);

void	throw_error(char *msg);

void 	throw_sys_error(char *msg);

void	jump_spaces(char **str);

#endif