/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figure_bonus.h"
#include "utils/utils_bonus_bonus.h"
#include "operations/figure_operations_bonus.h"
#include <math.h>

void	free_figure(t_figure *figure)
{
	free(figure->material.material_attrs);
	free(figure->attrs);
	free(figure->type);
	free(figure);
}

void	free_figures(t_figure *figures)
{
	t_figure	*figure;

	while (figures)
	{
		figure = figures;
		figures = figures->next;
		free_figure(figure);
	}
}

t_figure	*new_figure(char *type, t_point *position, t_color *color)
{
	t_figure	*figure;

	figure = ft_calloc(1, sizeof(t_figure));
	if (!figure)
		throw_sys_error("trying to allocate new figure");
	figure->type = ft_strdup(type);
	if (!figure->type)
		throw_sys_error("trying to allocate figure type");
	figure->position = *position;
	figure->color = *color;
	figure->glossiness = 256.0;
	figure->material = new_diffuse_mat();
	return (figure);
}

int	control_figure(t_figure *figure, t_camera *camera, t_controls *controls)
{
	t_point	translate_factor;
	t_point	rotation_factor;
	double	fact;

	if (!controls->moving_figure)
		return (0);
	fact = 4 * (M_PI / 180.0);
	translate_factor = wrap_point(
			0.2 * controls->move_right,
			0.2 * controls->move_up,
			0.2 * controls->move_front);
	rotation_factor = wrap_point(
			fact * controls->view_up,
			fact * controls->view_right,
			fact * controls->view_front);
	translate_figure(figure, camera, &translate_factor);
	if (figure->rotate)
		figure->rotate(figure, camera, &rotation_factor);
	if (figure->recalculate)
		figure->recalculate(figure);
	return (1);
}
