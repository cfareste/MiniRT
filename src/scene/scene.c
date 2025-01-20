/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:55:42 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/20 13:41:43 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/utils_bonus.h"
#include "scene.h"
#include "parser/parser.h"

void	add_figure(t_scene *scene, t_camera *camera)
{
	t_point			position;
	t_color			color;
	t_sphere_attrs	sp_attrs;
	t_figure		*new_figure;

	translate_point(&camera->position, &camera->front, camera->focus_dist * 4,
		&position);
	new_color(0.86, 0.86, 0.86, &color);
	sp_attrs.radius = 1.0;
	new_figure = new_sphere(&position, &color, &sp_attrs);
	new_figure->next = scene->figures;
	scene->figures = new_figure;
}
