#ifndef CYLINDER_H
# define CYLINDER_H
# define CYLINDER_ID "cy"

# include "shared/color/color.h"

typedef struct s_cylinder_attrs
{
	double			radius;
	double			height;
	t_coordinates	orientation;
}	t_cylinder_attrs;

typedef struct s_figure	t_figure;

void		set_cylinder_attrs(char **parts, t_cylinder_attrs *attrs,
				t_color *color);

t_figure	*new_cylinder(char **parts);

#endif
