#ifndef QUADRATIC_H
# define QUADRATIC_H

typedef struct s_root
{
	float	far;
	float	close;
}	t_root;

typedef struct s_quadratic_params
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	square_root;
	t_root	roots;
}	t_quadratic_params;

#endif
