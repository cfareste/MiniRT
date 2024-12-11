/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:44:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/11 12:39:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/scene.h"
#include "render/utils/reference_system/reference_system.h"
#include "scene/figure/types/box/default/box_default.h"
#include "scene/figure/types/cone/default/cone_default.h"
#include "scene/figure/types/cylinder/default/cylinder_default.h"
#include "scene/figure/types/disk/default/disk_default.h"
#include "scene/figure/types/plane/default/plane_default.h"
#include "scene/figure/types/quadrilater/default/quadrilater_default.h"
#include "scene/figure/types/sphere/default/sphere_default.h"
#include "libft.h"
#include <math.h>

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

void	handle_figure_movement(mlx_key_data_t *key_data, t_camera *camera,
	t_figure *figure)
{
	t_point		position;
	t_vector	projected;

	projected = camera->front;
	projected.y = 0.0;
	normalize(&projected);
	position = figure->position;
	if (key_data->key == MLX_KEY_W)
		translate_point(&position, &projected, 0.2, &figure->position);
	else if (key_data->key == MLX_KEY_S)
		translate_point(&position, &projected, -0.2, &figure->position);
	else if (key_data->key == MLX_KEY_A)
		translate_point(&position, &camera->right, -0.2, &figure->position);
	else if (key_data->key == MLX_KEY_D)
		translate_point(&position, &camera->right, 0.2, &figure->position);
	else if (key_data->key == MLX_KEY_SPACE)
		figure->position.y += 0.2;
	else if (key_data->key == MLX_KEY_LEFT_SHIFT)
		figure->position.y -= 0.2;
}

void	get_rotation_factor(keys_t key, t_point *factor)
{
	ft_bzero(factor, sizeof(t_point));
	if (key == MLX_KEY_UP)
		*factor = wrap_point(0, 5, 0);
	else if (key == MLX_KEY_DOWN)
		*factor = wrap_point(0, -5, 0);
	else if (key == MLX_KEY_LEFT)
		*factor = wrap_point(-5, 0, 0);
	else if (key == MLX_KEY_RIGHT)
		*factor = wrap_point(5, 0, 0);
}
