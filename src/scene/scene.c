/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:42 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/18 15:24:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "scene.h"
#include "parser/parser.h"

void	print_scene(t_scene *scene)
{
	t_light		*lights;
	t_figure	*figures;

	if (scene->ambient_light)
	{
		printf("Ambient ");
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
	print_scene_settings(&scene->settings);
}
