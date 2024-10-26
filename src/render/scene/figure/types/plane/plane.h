#ifndef PLANE_H
# define PLANE_H
# define PLANE_ID "pl"

# include "render/utils/coordinates/coordinates.h"
# include "render/scene/figure/figure.h"

typedef struct s_plane_attrs
{
	t_coordinates	orientation;
}	t_plane_attrs;

t_figure	*new_plane(char **parts);

void		set_plane(t_figure *plane, t_coordinates *position,
				t_plane_attrs *attrs);

#endif
