#include "libft.h"
#include "figure.h"
#include "utils.h"
#include "types/cylinder/cylinder.h"

t_figure	*new_figure(char *type, char *coord_str, char *color_str)
{
	t_figure	*new;

	new = ft_calloc(1, sizeof(t_figure));
	if (!new)
		throw_sys_error("trying to allocate new figure");
	new->type = ft_strdup(type);
	set_coordinates(coord_str, &new->position);
	set_color(color_str, &new->color);
	return (new);
}

int	push_figure(char **parts, t_figure **figure)
{
	t_figure	*new;
	t_figure	*aux;

	if (ft_strcmp(parts[0], CYLINDER_ID) == EQUAL_STRINGS)
		new = new_cylinder(parts);
	else if (ft_strcmp(parts[0], PLANE_ID) == EQUAL_STRINGS)
		new = new_plane(parts);
	else if (ft_strcmp(parts[0], SPHERE_ID) == EQUAL_STRINGS)
		new = new_sphere(parts);
	else
		return (0);
	if (!*figure)
		*figure = new;
	else
	{
		aux = *figure;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (1);
}

void	free_figures(t_figure *figures)
{
	t_figure	*figure;

	while (figures)
	{
		figure = figures;
		figures = figures->next;
		free(figure->attrs);
		free(figure->type);
		free(figure);
	}
}

void	print_figure(t_figure *figure)
{
	printf("%s (%p): %f, %f, %f | ", figure->type, figure,
		figure->position.x, figure->position.y, figure->position.z);
	figure->print_attrs(figure->attrs);
	printf(" | %f, %f, %f\n",
		figure->color.red, figure->color.green, figure->color.blue);
}
