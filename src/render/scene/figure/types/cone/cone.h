#pragma once

#define CONE_ID "co"

#include "render/utils/coordinates/coordinates.h"
#include "render/scene/figure/figure.h"

typedef struct s_cone_attrs
{
	double			radius;
	double			height;
	t_coordinates	orientation;
}	t_cone_attrs;

t_figure	*new_cone(char **parts);

void		set_cone(t_figure *cone, double radius, double height,
				t_cone_attrs *attrs);
