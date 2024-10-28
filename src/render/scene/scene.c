/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:42 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/28 17:55:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils.h"
#include "scene.h"
#include "parser/parser.h"

void	check_scene(t_scene *scene)
{
	t_light	*lights;
	int		mandatory_lights;

	if (!scene->camera)
		throw_error("A camera is needed to start rendering!");
	lights = scene->lights;
	mandatory_lights = 0;
	while (lights && mandatory_lights < 2)
	{
		if (lights->type == LIGHT_ID_MANDATORY)
			mandatory_lights++;
		lights = lights->next;
	}
	if (!scene->ambient_light || !mandatory_lights)
		throw_error("Some mandatory light is missing!");
	else if (mandatory_lights > 1)
		throw_error("Multiple lights for mandatory are not allowed");
}

void	print_scene(t_scene *scene)
{
	t_light		*lights;
	t_figure	*figures;

	if (scene->ambient_light)
	{
		ft_printf("Ambient ");
		print_light(scene->ambient_light);
	}
	if (scene->camera)
		print_camera(scene->camera);
	lights = scene->lights;
	while (lights)
	{
		print_light(lights);
		lights = lights->next;
	}
	if (scene->figures)
		ft_printf("\nFigures:\n");
	figures = scene->figures;
	while (figures)
	{
		print_figure(figures);
		figures = figures->next;
	}
}
