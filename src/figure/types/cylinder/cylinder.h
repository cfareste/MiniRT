#ifndef CYLINDER_H
# define CYLINDER_H
# define CYLINDER_ID "cy"

# include "utils.h"

typedef struct s_cylinder_attrs
{
	double			diameter;
	double			height;
	t_coordinates	orientation;
}	t_cylinder_attrs;

#endif