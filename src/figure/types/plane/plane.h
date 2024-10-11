#ifndef PLANE_H
# define PLANE_H
# define PLANE_ID "pl"

# include "shared/coordinates/coordinates.h"

typedef struct s_plane_attrs
{
	t_coordinates	orientation;
}	t_plane_attrs;

t_figure	*new_plane(char **pieces);

#endif