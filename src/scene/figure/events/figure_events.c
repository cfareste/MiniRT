/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:02 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/10 17:56:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "scene/scene.h"
#include "render/utils/reference_system/reference_system.h"
#include "libft.h"
#include <math.h>

static void	handle_figure_movement(mlx_key_data_t *key_data, t_camera *camera,
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

void	handle_figure_rotation(t_vector *orientation, t_vector *factor)
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
	normalize(orientation);
}

static void	get_rotation_factor(keys_t key, t_point *factor)
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

void	handle_figure_event(mlx_key_data_t *key_data, t_scene *scene,
	t_figure *figure)
{
	t_point	factor;

	handle_figure_movement(key_data, scene->camera, figure);
	get_rotation_factor(key_data->key, &factor);
	if (factor.x == 0.0 && factor.y == 0.0 && factor.z == 0.0)
		return ;
	if (figure->rotate)
		figure->rotate(figure, &factor);
}
