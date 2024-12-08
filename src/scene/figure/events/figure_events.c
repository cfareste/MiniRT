/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/08 18:43:43 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "scene/figure/figure.h"
#include "render/utils/reference_system/reference_system.h"
#include "libft.h"
#include <math.h>

static void	handle_figure_movement(mlx_key_data_t *key_data, t_figure *figure)
{
	if (key_data->key == MLX_KEY_W)
		figure->position.z -= 0.2;
	else if (key_data->key == MLX_KEY_S)
		figure->position.z += 0.2;
	else if (key_data->key == MLX_KEY_A)
		figure->position.x -= 0.2;
	else if (key_data->key == MLX_KEY_D)
		figure->position.x += 0.2;
	else if (key_data->key == MLX_KEY_SPACE)
		figure->position.y += 0.2;
	else if (key_data->key == MLX_KEY_LEFT_SHIFT)
		figure->position.y -= 0.2;
}

void handle_figure_rotation(t_vector *orientation, t_vector *factor)
{
	double	yaw;
	double	pitch;

	get_vector_angles(orientation, &yaw, &pitch);
	yaw += factor->x;
	pitch += factor->y;
	if (yaw <= 0.0)
		yaw += 360.0;
	else if (yaw >= 360.0)
		yaw -= 360.0;
	pitch = ft_clamp(pitch, -90, 90) * (M_PI / 180.0);
	yaw *= M_PI / 180.0;
	get_world_axis(orientation, FRONT);
	rotate_by_axis(RIGHT, pitch, orientation);
	rotate_by_axis(UP, -yaw, orientation);
}

static void	get_rotation_factor(keys_t key, t_point *factor)
{
	if (key == MLX_KEY_UP)
		*factor = wrap_point(0, 5, 0);
	else if (key == MLX_KEY_DOWN)
		*factor = wrap_point(0, -5, 0);
	else if (key == MLX_KEY_LEFT)
		*factor = wrap_point(-5, 0, 0);
	else if (key == MLX_KEY_RIGHT)
		*factor = wrap_point(5, 0, 0);
}

void	handle_figure_event(mlx_key_data_t *key_data, t_figure *figure)
{
	t_point	factor;

	handle_figure_movement(key_data, figure);
	get_rotation_factor(key_data->key, &factor);
	if (ft_strcmp(figure->type, SPHERE_ID) != EQUAL_STRINGS)
	{
		handle_figure_rotation(&figure->cy_attrs->orientation, &factor);
	}
}
