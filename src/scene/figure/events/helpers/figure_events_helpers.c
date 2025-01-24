/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:44:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:43:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "scene/figure/types/box/default/box_default.h"
#include "scene/figure/types/cone/default/cone_default.h"
#include "scene/figure/types/cylinder/default/cylinder_default.h"
#include "scene/figure/types/disk/default/disk_default.h"
#include "scene/figure/types/plane/default/plane_default.h"
#include "scene/figure/types/quadrilater/default/quadrilater_default.h"
#include "scene/figure/types/sphere/default/sphere_default.h"
#include "scene/figure/material/types/metallic/default/metallic_default.h"
#include "scene/figure/material/types/plastic/default/plastic_default.h"
#include "scene/figure/material/types/glass/default/glass_default.h"
#include "scene/figure/material/types/emissive/default/emissive_default.h"
#include "libft.h"
#include <math.h>

t_material	get_next_material_type(t_figure *figure)
{
	t_material	next_material;

	if (figure->material.type == DIFFUSE)
		next_material = new_metallic_default_mat();
	else if (figure->material.type == METALLIC)
		next_material = new_plastic_default_mat();
	else if (figure->material.type == PLASTIC)
		next_material = new_glass_default_mat();
	else if (figure->material.type == GLASS)
		next_material = new_emissive_default_mat();
	else
		next_material = new_diffuse_mat();
	return (next_material);
}

t_figure	*get_next_figure_type(t_figure *figure)
{
	t_point		pos;
	t_color		color;
	t_figure	*next_figure;

	color = figure->color;
	pos = figure->position;
	if (ft_strcmp(figure->type, CONE_ID) == EQUAL_STRINGS)
		translate_point(&pos, &figure->co_attrs->orientation,
			figure->co_attrs->height / 2.0, &pos);
	if (ft_strcmp(figure->type, SPHERE_ID) == EQUAL_STRINGS)
		next_figure = new_plane_default(&pos, &color);
	else if (ft_strcmp(figure->type, PLANE_ID) == EQUAL_STRINGS)
		next_figure = new_cylinder_default(&pos, &color);
	else if (ft_strcmp(figure->type, CYLINDER_ID) == EQUAL_STRINGS)
		next_figure = new_cone_default(&pos, &color);
	else if (ft_strcmp(figure->type, CONE_ID) == EQUAL_STRINGS)
		next_figure = new_disk_default(&pos, &color);
	else if (ft_strcmp(figure->type, DISK_ID) == EQUAL_STRINGS)
		next_figure = new_quadrilater_default(&pos, &color);
	else if (ft_strcmp(figure->type, QUAD_ID) == EQUAL_STRINGS)
		next_figure = new_box_default(&pos, &color);
	else
		next_figure = new_sphere_default(&pos, &color);
	return (next_figure);
}

void	get_translation_factor(keys_t key, t_vector *factor)
{
	ft_bzero(factor, sizeof(t_vector));
	if (key == MLX_KEY_W)
		*factor = wrap_point(0, 0, 0.2);
	else if (key == MLX_KEY_S)
		*factor = wrap_point(0, 0, -0.2);
	else if (key == MLX_KEY_A)
		*factor = wrap_point(-0.2, 0, 0);
	else if (key == MLX_KEY_D)
		*factor = wrap_point(0.2, 0, 0);
	else if (key == MLX_KEY_SPACE)
		*factor = wrap_point(0, 0.2, 0);
	else if (key == MLX_KEY_LEFT_SHIFT)
		*factor = wrap_point(0, -0.2, 0);
}

void	get_rotation_factor(keys_t key, modifier_key_t mod, t_point *factor)
{
	float	angle;

	ft_bzero(factor, sizeof(t_point));
	angle = 5 * (M_PI / 180.0);
	if (key == MLX_KEY_UP)
		*factor = wrap_point(-angle, 0, 0);
	else if (key == MLX_KEY_DOWN)
		*factor = wrap_point(angle, 0, 0);
	else if (key == MLX_KEY_LEFT && mod == MLX_CONTROL)
		*factor = wrap_point(0, 0, -angle);
	else if (key == MLX_KEY_RIGHT && mod == MLX_CONTROL)
		*factor = wrap_point(0, 0, angle);
	else if (key == MLX_KEY_LEFT)
		*factor = wrap_point(0, -angle, 0);
	else if (key == MLX_KEY_RIGHT)
		*factor = wrap_point(0, angle, 0);
}
