#ifndef RENDER_H
# define RENDER_H

# include "shared/coordinates/coordinates.h"
# include "figure/figure.h"

typedef struct s_hit_record
{
	t_figure	*figure;
	float		distance;
	t_coordinates	point;
	t_coordinates	normal;
}	t_hit_record;

typedef struct s_bounds
{
	float	max;
	float	min;
}	t_bounds;

typedef struct s_ray
{
	t_coordinates	origin;
	t_coordinates	direction;
	t_bounds		bounds;
}	t_ray;

#endif