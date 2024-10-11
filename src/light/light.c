#include "scene.h"
#include "libft.h"

int	set_ambient_light(char **pieces, t_light *light)
{
	if (!pieces[1] || !pieces[2])
		throw_error("Missing ambient light params");
	light->brightness = ft_atod(pieces[1]);
	set_color(pieces[2], &light->color);
	light->next = NULL;
	light->position.x = -1;
	light->position.y = -1;
	light->position.z = -1;
	return (1);
}

static t_light	*new_light(t_light **lights)
{
	t_light	*new;

	new = ft_calloc(1, sizeof(t_light));
	if (!new)
		throw_sys_error("trying allocate t_light");
	new->next = NULL;
	if (*lights)
		(*lights)->next = new;
	else
		*lights = new;
	return (new);
}

void	push_light(char **pieces, t_light **lights)
{
	t_light	*light;

	if (!pieces[1] || !pieces[2] || !pieces[3])
		throw_error("Missing light params");
	light = new_light(lights);
	set_coordinates(pieces[1], &light->position);
	light->brightness = ft_atod(pieces[2]);
	set_color(pieces[3], &light->color);
	if (light->brightness < 0 || light->brightness > 1.0)
		throw_error("Light brightness must be [0.0,1.0]");
}

void	free_lights(t_light *lights)
{
	t_light	*aux;

	while (lights)
	{
		aux = lights;
		lights = lights->next;
		free(aux);
	}
}

void	print_light(t_light *light)
{
	printf("Light (%p): %f, %f, %f | %f | %i, %i, %i\n",
		light,
		light->position.x, light->position.y, light->position.z,
		light->brightness,
		light->color.red, light->color.green, light->color.blue);
}
