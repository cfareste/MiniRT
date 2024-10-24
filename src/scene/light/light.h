#ifndef LIGHT_H
# define LIGHT_H

# include "float.h"
# include "shared/color/color.h"
# include "shared/coordinates/coordinates.h"

typedef enum e_light_types
{
	LIGHT_ID = 'l',
	LIGHT_ID_MANDATORY = 'L',
	AMBIENT_LIGHT_ID = 'A'
}	t_light_type;

typedef struct s_light
{
	t_light_type	type;
	t_coordinates	position;
	double			brightness;
	struct s_light	*next;
	t_color			color;
}	t_light;

int		set_ambient_light(char **parts, t_light **light);

void	push_light(char **parts, t_light **lights);

void	free_lights(t_light *lights);

void	print_light(t_light *light);

#endif