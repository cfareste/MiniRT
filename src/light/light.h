#ifndef LIGHT_H
# define LIGHT_H
# define LIGHT_ID 'L'
# define AMBIENT_LIGHT_ID 'A'

# include "float.h"
# include "color/color.h"
# include "coordinates.h"

typedef struct s_light
{
	t_coordinates	position;
	double			brightness;
	struct s_light	*next;
	t_color			color;
}	t_light;

int		set_ambient_light(char **pieces, t_light **light);

void	push_light(char **pieces, t_light **lights);

void	free_lights(t_light *lights);

void	print_light(t_light *light);

#endif