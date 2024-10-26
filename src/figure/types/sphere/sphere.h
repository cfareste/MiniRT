#ifndef SPHERE_H
# define SPHERE_H
# define SPHERE_ID "sp"

typedef struct s_sphere_attrs
{
	double	radius;
}	t_sphere_attrs;

typedef struct s_figure	t_figure;

t_figure	*new_sphere(char **parts);

#endif
