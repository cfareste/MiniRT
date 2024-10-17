#include "scene.h"
#include "libft.h"

int	set_ambient_light(char **parts, t_light **light)
{
	if (*light)
		throw_error("Multiple ambient lights are not allowed");
	if (!parts[1] || !parts[2])
		throw_error("Missing ambient light params");
	*light = ft_calloc(1, sizeof(t_light));
	if (!*light)
		throw_sys_error("trying to allocate ambient light");
	(*light)->type = AMBIENT_LIGHT_ID;
	(*light)->brightness = ft_atod(parts[1], throw_sys_error, "ft_atod");
	set_color(parts[2], &(*light)->color);
	(*light)->position.x = -1;
	(*light)->position.y = -1;
	(*light)->position.z = -1;
	return (1);
}

static t_light	*new_light(t_light **lights)
{
	t_light	*new;
	t_light	*aux;

	new = ft_calloc(1, sizeof(t_light));
	if (!new)
		throw_sys_error("trying allocate t_light");
	new->next = NULL;
	if (!*lights)
		*lights = new;
	else
	{
		aux = *lights;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (new);
}

void	push_light(char **parts, t_light **lights)
{
	t_light	*light;

	if (!parts[1] || !parts[2] || !parts[3])
		throw_error("Missing light params");
	light = new_light(lights);
	light->type = *parts[0];
	set_coordinates(parts[1], &light->position);
	light->brightness = ft_atod(parts[2], throw_sys_error, "ft_atod");
	set_color(parts[3], &light->color);
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
