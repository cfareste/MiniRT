/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:13 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/03 18:55:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_events.h"
#include "../helpers/camera_helper.h"
#include "render/renderer/renderer_bonus.h"

static int	movement_event(keys_t key, t_camera *camera)
{
	if (key == MLX_KEY_UP)
		update_camera_front(camera, wrap_point(0, 0.02, 0));
	else if (key == MLX_KEY_DOWN)
		update_camera_front(camera, wrap_point(0, -0.02, 0));
	else if (key == MLX_KEY_LEFT)
		update_camera_front(camera, wrap_point(-0.02, 0, 0));
	else if (key == MLX_KEY_RIGHT)
		update_camera_front(camera, wrap_point(0.02, 0, 0));
	else if (key == MLX_KEY_SPACE)
		update_camera_pos(camera, wrap_point(0, 0.2, 0));
	else if (key == MLX_KEY_LEFT_SHIFT || key == MLX_KEY_RIGHT_SHIFT)
		update_camera_pos(camera, wrap_point(0, -0.2, 0));
	else if (key == MLX_KEY_W)
		update_camera_pos(camera, wrap_point(0, 0, 0.2));
	else if (key == MLX_KEY_S)
		update_camera_pos(camera, wrap_point(0, 0, -0.2));
	else if (key == MLX_KEY_A)
		update_camera_pos(camera, wrap_point(-0.2, 0, 0));
	else if (key == MLX_KEY_D)
		update_camera_pos(camera, wrap_point(0.2, 0, 0));
	else
		return (0);
	return (1);
}

void	camera_key_events(mlx_key_data_t keydata, t_window *window)
{
	if (keydata.key == MLX_KEY_I)
		update_camera_fov(window->render.scene.camera, -1);
	else if (keydata.key == MLX_KEY_O)
		update_camera_fov(window->render.scene.camera, 1);
	else if (keydata.key == MLX_KEY_K)
		update_camera_focus_dis(window->render.scene.camera, -1);
	else if (keydata.key == MLX_KEY_J)
		update_camera_focus_dis(window->render.scene.camera, 1);
	else if (!movement_event(keydata.key, window->render.scene.camera))
		return ;
	render(window);
}
