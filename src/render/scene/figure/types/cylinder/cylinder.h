#pragma once
#define CYLINDER_H
#define CYLINDER_ID "cy"

#include "render/utils/color/color.h"
#include "render/scene/figure/figure.h"

typedef struct s_cylinder_attrs
{
	double			diameter;
	double			height;
	t_coordinates	orientation;
}	t_cylinder_attrs;

void		set_cylinder_attrs(char **parts, t_cylinder_attrs *attrs,
				t_color *color);

t_figure	*new_cylinder(char **parts);
