/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:37 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:33 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "light.h"

t_light	*new_light(t_light **lights)
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
	printf("Light (%p): %f, %f, %f | %f | %f, %f, %f\n",
		light,
		light->position.x, light->position.y, light->position.z,
		light->brightness,
		light->color.red, light->color.green, light->color.blue);
}
