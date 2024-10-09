#ifndef FIGURE_H
# define FIGURE_H

# include "utils.h"
# include "sphere/sphere.h"
# include "plane/plane.h"
# include "cylinder/cylinder.h"

typedef struct s_figure
{
	char			*type;
	t_coordinates	position;
	t_color			color;
	void			(*hit)(void);
	union
	{
		t_sphere_attrs		*sp_attrs;
		t_plane_attrs		*pl_attrs;
		t_cylinder_attrs	*cy_attrs;
	};
}	t_figure;

#endif