#ifndef FIGURE_H
# define FIGURE_H

# include "render/ray/ray.h"
# include "types/plane/plane.h"
# include "types/sphere/sphere.h"
# include "types/cylinder/cylinder.h"
# include "render/utils/color/color.h"
# include "render/utils/vector/vector.h"
# include "render/utils/coordinates/coordinates.h"

typedef struct s_figure
{
	char	*type;
	t_point	position;
	t_color	color;
	int		(*hit)(t_figure *figure, t_ray *ray, float *distance);
	void	(*normal)(t_figure *figure, t_point *point, t_vector *res);
	void	(*print_attrs)(void *attrs);
	void	(*free)(t_figure *figure);
	union
	{
		void				*attrs;
		t_sphere_attrs		*sp_attrs;
		t_plane_attrs		*pl_attrs;
		t_cylinder_attrs	*cy_attrs;
	};
	t_figure		*next;
}	t_figure;

int			push_figure(char **parts, t_figure **figure);

void		free_figures(t_figure *figures);

t_figure	*new_figure(char *type, char *coord_str, char *color_str);

void		print_figure(t_figure *figure);

#endif
