#ifndef LIGHT_H
# define LIGHT_H
# define LIGHT_ID "L"
# define AMBIENT_LIGHT_ID 'A'

# include "utils.h"

typedef struct s_light
{
	t_coordinates	position;
	double			strength;
	t_color			color;
}	t_light;

#endif