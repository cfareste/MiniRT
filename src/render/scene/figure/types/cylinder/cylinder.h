#pragma once
#define CYLINDER_H
#define CYLINDER_ID "cy"

#include "render/utils/color/color.h"
#include "render/scene/figure/figure.h"
#include "render/ray/ray.h"

typedef struct s_cylinder_attrs
{
	double			radius;
	double			height;
	t_coordinates	orientation;
}	t_cylinder_attrs;

typedef struct s_reference_system
{
	t_ray			ray;
	t_coordinates	center;
}	t_reference_system;

void		set_cylinder(char **parts, t_cylinder_attrs *attrs,
				t_color *color);

t_figure	*new_cylinder(char **parts);
