/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/09 20:22:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "figure.h"
#include "utils/utils_bonus.h"
#include "texture/bump_map/bump_map.h"
#include "render/utils/random/random.h"

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

void	print_figure(t_figure *figure)
{
	printf("%s (%p): %f, %f, %f | ", figure->type, figure,
		figure->position.x, figure->position.y, figure->position.z);
	figure->print_attrs(figure->attrs);
	printf(" | %f, %f, %f | ",
		figure->color.red, figure->color.green, figure->color.blue);
	print_texture(&figure->bump_map);
}

t_figure	*create_default_figure(t_point *position)
{
	t_figure	*figure;
	uint32_t	seed;

	figure = ft_calloc(1, sizeof(t_figure));
	if (!figure)
		throw_sys_error("error allocating new figure");
	figure->type = ft_strdup(SPHERE_ID);
	if (!figure->type)
		throw_sys_error("error allocating figure type");
	figure->position = *position;
	seed = mlx_get_time() * 100000;
	figure->color.red = get_random_float(&seed);
	figure->color.green = get_random_float(&seed);
	figure->color.blue = get_random_float(&seed);
	figure->color.alpha = 1.0;
	figure->sp_attrs = ft_calloc(1, sizeof(t_sphere_attrs));
	if (!figure->sp_attrs)
		throw_sys_error("error allocating new sphere attributes");
	figure->sp_attrs->radius = 1.0;
	figure->material.material_attrs = NULL;
	return (figure);
}
