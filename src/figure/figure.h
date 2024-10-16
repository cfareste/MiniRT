#ifndef FIGURE_H
# define FIGURE_H

# include "sphere/sphere.h"
# include "plane/plane.h"
# include "cylinder/cylinder.h"
# include "shared/coordinates/coordinates.h"
# include "shared/color/color.h"
# include "render/ray/ray.h"

typedef struct s_figure
{
	char			*type;
	t_coordinates	position;
	t_color			color;
	int				(*hit)(t_figure *figure, t_ray *ray, float *distance);
	void			(*print_attrs)(void *attrs);
	void			(*free)(t_figure *figure);
	union
	{
		void				*attrs;
		t_sphere_attrs		*sp_attrs;
		t_plane_attrs		*pl_attrs;
		t_cylinder_attrs	*cy_attrs;
	};
	t_figure		*next;
}	t_figure;

int			push_figure(char **pieces, t_figure **figure);

void		free_figures(t_figure *figures);

t_figure	*new_figure(char *type, char *coord_str, char *color_str);

void		print_figure(t_figure *figure);

#endif